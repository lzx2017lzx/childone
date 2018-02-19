#include<sys/types.h>
#include<semaphore.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/epoll.h>
#include<list>
#include<map>
#include<arpa/inet.h>
#include<pthread.h>
#include<sys/epoll.h>
#include<unistd.h>
#include"cJSON.h"
#include"json.h"
#include"mysqllib.h"
#include"myredis.h"
#include<openssl/md5.h>
#include<iostream>
#include"WRITEREADAVOIDPASTE.h"
#include"opensslmd5API.h"

#define CREATE_DAEMON if(fork()>0)exit(1);setsid();

using namespace std;


//用于调用accept的线程数量
int accept_threads=4;
//用于处理数据的线程数量
int worker_threads=8;

class AutoLock
{
	public:
		AutoLock(pthread_mutex_t & mutex):mutex(mutex)
	{
		pthread_mutex_lock(&mutex);
	}
		~AutoLock()
		{
			pthread_mutex_unlock(&mutex);
		}
		pthread_mutex_t & mutex;


};

#define MyLock(mutex) AutoLock __tmp__lock___(mutex)
//一条连接对应的通道，保存通道的临时数据
class Channel
{
	public:
		char *buf;
		uint32_t packetSize;
		uint32_t readSize;
		int fd;

		Channel(int fd):packetSize(0),readSize(0),fd(fd)
	{
		buf=new char[4096];
		memset(buf,0,4096);
	}
		~Channel()
		{
			printf("socket closed.\n");
			close(fd);delete[]buf;

		}

};

//多线程使用的消息队列,锁和信号量
pthread_mutex_t mutex;
sem_t sem;
list<Channel*>channels;

//服务器socket文件描述符
int server;

//epoll文件描述符
int epollfd;

void epoll_add(int newfd)
{
	Channel*channel=new Channel(newfd);
	struct epoll_event ev;
	ev.data.ptr=channel;
	ev.events=EPOLLIN|EPOLLONESHOT;
	epoll_ctl(epollfd,EPOLL_CTL_ADD,newfd,&ev);
}

void epoll_mod(Channel*channel)
{
	struct epoll_event ev;
	ev.data.ptr=channel;
	ev.events=EPOLLIN|EPOLLONESHOT;
	epoll_ctl(epollfd,EPOLL_CTL_MOD,channel->fd,&ev); 
}


void *accept_thread_func(void *ptr)
{
	while(1)
	{
		printf("before accept.\n");
		int newfd=accept(server,NULL,NULL);
		printf("accpet ok newfd:%d\n",newfd);
		if(newfd>0)
		{
			//修改为非阻塞
			int flags;
			flags=fcntl(newfd,F_GETFL);
			flags|=O_NONBLOCK;
			fcntl(newfd,F_SETFL,&flags);
			epoll_add(newfd);
		}

	}
	return NULL;
}


Channel* readData(Channel*channel)
{
	int ret;
	if(channel->readSize<4)
	{
		ret=read(channel->fd,channel->buf+channel->readSize,4-channel->readSize);
		printf("readData readSize<4:%s,ret:%d\n",channel->buf+channel->readSize,ret);
		if(ret>0)
		{
			channel->readSize+=ret;
			if(channel->readSize==4)
			{
				uint32_t tmp=*(uint32_t*)channel->buf;
				channel->packetSize=ntohl(tmp);
				printf("channel->packetSize:%d\n",channel->packetSize);
			}
			return readData(channel);

		}

	}
	else
	{
		ret=read(channel->fd,channel->buf+channel->readSize,channel->packetSize+4-channel->readSize);
		printf("readData:readSize>4:%s,ret:%d\n",channel->buf+channel->readSize,ret);
		if(ret>0)
		{
			printf("before channel->readSize+=ret.\n");
			channel->readSize+=ret;

			printf("after channel->readSize+=ret.channel->readSize:%d\n",channel->readSize);
			printf("channel->packetSize:%d\n",channel->packetSize);
			if(channel->readSize==channel->packetSize+4)
			{
				printf("readSize==packetSize+4.\n");
				return channel;
			}
			else
				return readData(channel);
		}

	}

	if(ret==0||(ret<0&&errno!=EAGAIN))//对方已经关闭了socket,或者socket有错误
	{
		printf("ret=%d,errno=%d\n",ret,errno);
		delete channel;//服务器端也关闭socket，清理内存
	}else
	{
		epoll_mod(channel);
	}
	return NULL;
}

int handleredis(Channel*channel)
{
	//解包
	Json resp;
	string temp(channel->buf+4);
	resp.parse(temp);
	string username=resp.getString("username");
	string password=resp.getString("password");
	string type=resp.getString("type");
	double lat=resp.getDouble("lat");
	cout<<"handleredis:lat:"<<lat<<endl;
	double lng=resp.getDouble("lng");
	cout<<"handleredis:lng:"<<lng<<endl;
	int geohash=resp.getInt("geohash");
	cout<<"handleredis:geohash:"<<geohash<<endl;

	Redis redis;
	redis.addSet(type,username);
	if(redis.addSet(type,username)!=0)
	{
		cout<<"addSet is wrong."<<endl;
		return -1;
	}

	list<string>lisstrkey;
	lisstrkey.push_back("status");
	lisstrkey.push_back("lat");
	lisstrkey.push_back("lng");
	lisstrkey.push_back("type");
	lisstrkey.push_back("geohash");

	list<string>lisstrvalue;
	lisstrvalue.push_back("0");
	std::stringstream ss;
	ss<<lat;
	string tempstr;
	ss>>tempstr;
	lisstrvalue.push_back(tempstr);
	ss.str("");
	if(ss.eof())
	{
		ss.clear();
	}
	ss<<lng;
	tempstr=string();
	ss>>tempstr;
	printf("after ss<<lng ss>>tempstr:tempstr:%s\n",tempstr.c_str());
	lisstrvalue.push_back(tempstr);
	lisstrvalue.push_back(type);
	ss.str("");
	if(ss.eof())
	{
		ss.clear();
	}
	ss<<geohash;
	tempstr=string();
	ss>>tempstr;
	printf("after ss<<geohash ss>>tempstr:tempstr:%s\n",tempstr.c_str());
	lisstrvalue.push_back(tempstr);	
	if(redis.addHash(username,lisstrkey,lisstrvalue))
	{
		cout<<"addHash error.\n"<<endl;
		return -1;
	};

	if(type=="d")
	{

		if(redis.addSet(tempstr,username))
			return -2;
	}

	if(type=="d")
		cout<<"laosiji:"<<username<<"online...";
	else
		cout<<"shuke"<<username<<"online...";
	return 0;
}
int loginuser(string username,string password,Channel*channel)
{
	printf("username:%s\n",username.c_str());
	printf("password:%s\n",password.c_str());

	char sqlcommand[1024]={0};
	const char *passwordtemp=MYMD5((const char*)password.c_str());
	printf("passwordtemp:%s\n",passwordtemp);
	sprintf(sqlcommand, "select * from tuser where username = '%s' and fpassword = '%s';", username.c_str(), passwordtemp);
	printf("sqlcommand:%s\n",sqlcommand);
	char charreturn[4096]={0};
	char chartemp[4096]={0};
	Json res;

	mysqllib *mysql = mysqllib::getInstance();
	printf("mysql:");
	if(mysql->select(sqlcommand))
	{
		//数据库中不存在该人员，登录失败
		strcpy(charreturn,"login failed");
		printf("charreturn:%s\n",charreturn);
		memset(sqlcommand,0,sizeof(sqlcommand));
		res.add("response",charreturn);
		strcpy(chartemp,res.print());
		mywritebuf(channel->fd,chartemp);
		return -1;
	}else
	{
		strcpy(charreturn,"login success");
		printf("charreturn:%s\n",charreturn);
		res.add("response",charreturn);
		int ret=handleredis(channel);
		if(ret==0)
		{
			cout<<"handleredis is ok:ret"<<ret<<endl;
			strcat(charreturn,"handlerredis is ok");
			res.add("storedatas","ok");
		}else
		{
			cout<<"handleredis is not ok"<<ret<<endl;
			strcat(charreturn,"but handlerredis is not ok");
			res.add("storedatas","fail");
		}
		strcpy(chartemp,res.print());
		printf("chartemp:%s\n",res.print());
		mywritebuf(channel->fd,chartemp);
		return 0;
	}
}

int registeruser(string username,string password,Channel*channel)
{
	printf("username:%s\n",username.c_str());
	printf("password:%s\n",password.c_str());

	char sqlcommand[1024]={0};
	const char *passwordtemp=MYMD5((const char*)password.c_str());
	printf("passwordtemp:%s\n",passwordtemp);
	sprintf(sqlcommand, "select * from tuser where username = '%s' and fpassword = '%s';", username.c_str(), passwordtemp);
	printf("sqlcommand:%s\n",sqlcommand);
	char charreturn[4096]={0};
	char chartemp[4096]={0};

	mysqllib *mysql = mysqllib::getInstance();
	printf("mysql:");
	if(mysql->select(sqlcommand))
	{
		//数据库中不存在该人员,插入数据，执行注册程序
		strcpy(charreturn,"register failed");
		printf("charreturn:%s\n",charreturn);
		memset(sqlcommand,0,sizeof(sqlcommand));
		sprintf(sqlcommand, "insert into tuser(username,fpassword) values('%s','%s')", username.c_str(), passwordtemp);
		if(mysql->insert(sqlcommand))
		{
			strcpy(charreturn,"register failed");
			printf("charreturn:%s\n",charreturn);
			printf("query error\n");
			Json res;
			res.add("response",charreturn);
			strcpy(chartemp,res.print());
			mywritebuf(channel->fd,chartemp);
			return -2;

		};
		strcpy(charreturn,"register success");
		printf("charreturn:%s\n",charreturn);
		Json res;
		res.add("response",charreturn);
		strcpy(chartemp,res.print());
		mywritebuf(channel->fd,chartemp);
		return 0;

	}else
	{
		strcpy(charreturn,"you are already registed.\n");
		printf("charreturn:%s\n",charreturn);
		Json res;
		res.add("response",charreturn);
		strcpy(chartemp,res.print());
		mywritebuf(channel->fd,chartemp);
		return 0;
	}

}

//将string类型变量转换成数字类型

	template<class T>
T stringtonumber(const string &str)//如果不加const 形参是匿名对象不会成功传参
{
	std::stringstream ss(str);
	T number;
	ss>>number;
	return number;
}

int getnearbydrivers(Channel*channel)
{
	//从json报文中提取信息
	Json resp;
	string temp(channel->buf+4);
	printf("channel->buf+4:%s\n",channel->buf+4);
	resp.parse(temp);
	string username=resp.getString("username");
	double lat=resp.getDouble("lat");
	double lng=resp.getDouble("lng");
	int geohash=resp.getInt("geohash");

	cout<<"get nearby driver:"<<geohash;
	Redis redis;


	int driverCount=0;
	JsonArray driversjsonarray;
	static int off[]={0,1,-1,2,-2};
	for(int i=0;i<sizeof(off)/sizeof(off[0]);++i)
	{
		int geokey=geohash+off[i];
std:stringstream sstring;
    sstring<<geohash;
    string temp;
    sstring>>temp;
    list<string> drivers=redis.getSet(temp);

    list<string>::iterator it1=drivers.begin();
    printf("\ndrivers size:%lu\n",drivers.size());
    for(;it1!=drivers.end();it1++)
    {
	    Json driver;
	    driver.add("name",*it1);
	    printf("name:%s\n",(*it1).c_str());
	    double lat=stringtonumber<double>(redis.getHashMember(*it1,"lat"));
	    printf("lat:%lf\n",lat);
	    driver.add("lat",lat);
	    double lng=stringtonumber<double>(redis.getHashMember(*it1,"lng"));
	    printf("lng:%lf\n",lng);
	    driver.add("lng",lng);
	    driver.getroot();
	    driversjsonarray.addarray(driver.getroot());

	    driverCount++;
	    if(driverCount>=10)
		    break;
	    printf("drivercount:%d\n",driverCount);
    }
	
    cout<<"internal circle ends."<<endl;
	printf("driversjsonarray.print():%s\n",driversjsonarray.print());
    if(driverCount>=10)
	    break;
	}
	printf("1\n");
	printf("2\n");
	//printf("dirvers:%s\n",driversjsonarray.print());
	Json respagain;
	respagain.add("drivers",driversjsonarray.getJsonArray());
	respagain.add("response","ok");

	mywritebuf(channel->fd,respagain.print());
	return 0;	
}

void handleData(Channel*channel)
{
	printf("handleData is working.\n");
	channel->buf[channel->readSize]=0;
	printf("channel 1\n");
	channel->readSize=0;//不要忘记清零
	printf("channel 2\n");
	Json resp;
	printf("channel 3\n");
	string temp(channel->buf+4);
	cout<<"temp:"<<temp<<endl;
	printf("channel 4\n");
	resp.parse(temp);
	printf("channel 5\n");
	string username=resp.getString("username");
	string cmd=resp.getString("cmd");
	if(cmd=="register")
	{
		string password=resp.getString("password");
		if(!registeruser(username,password,channel))
			printf("regist ok.\n");
	}else if(cmd=="login")
	{
		string password=resp.getString("password");
		printf("login process is working.\n");
		if(!loginuser(username,password,channel))
			printf("login ok.\n");
	}else if(cmd=="nearbyDriver")
	{
		printf("nearbyDriver is working.\n");
		if(!getnearbydrivers(channel))
			printf("nearbydriver ok.\n");

	}

	epoll_mod(channel);

}

void * worker_thread_func(void *ptr)
{
	while(1)
	{
		sem_wait(&sem);

		Channel* channel=NULL;

		{
			MyLock(mutex);
			if(channels.size()==0)
				break;
			channel=*channels.begin();
			channels.erase(channels.begin());

		}

		if(readData(channel))
		{
			printf("before handleData.\n");
			handleData(channel);
		}

		//把channel加回
	}
	return NULL;
}
void init()
{
	server=socket(AF_INET,SOCK_STREAM,0);
	//设置结诟体，用来绑定IP和端口
	struct sockaddr_in addr;
	addr.sin_addr.s_addr=inet_addr("0.0.0.0");
	addr.sin_family=AF_INET;
	addr.sin_port=htons(10099);    

	//绑定地址端口/信息到socket文件
	bind(server,(struct sockaddr*)&addr,sizeof(addr));

	//监听
	listen(server,250);//同时监听10个客户端

	epollfd=epoll_create(1024);
	pthread_t tid;
	//创建一堆线程
	for(int i=0;i<accept_threads;++i)
	{
		pthread_create(&tid,NULL,accept_thread_func,NULL);
	}

	for(int i=0;i<worker_threads;++i)
	{
		pthread_create(&tid,NULL,worker_thread_func,NULL);

	}

	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutex,&attr);
	sem_init(&sem,0,0);
}


void exec()
{
	struct epoll_event evs[8];
	while(1)
	{
		int ret=epoll_wait(epollfd,evs,8,5000);
		if(ret>0)
		{
			for(int i=0;i<ret;i++)
			{
				Channel*channel=(Channel*)evs[i].data.ptr;

				{
					MyLock(mutex);
					channels.push_back(channel);
				}

				sem_post(&sem);//让工作线程抢channel对象
			}
		}else if(ret<0&&errno!=EINTR)
		{
			break;
		}

	}
}

int main()
{
	CREATE_DAEMON
	init();
	exec();

	return 0;
}
