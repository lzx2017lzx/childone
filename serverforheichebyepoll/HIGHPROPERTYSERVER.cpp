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
#include<iostream>
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
        if(ret>0)
        {
            channel->readSize+=ret;
            if(channel->readSize==4)
            {
                uint32_t tmp=*(uint32_t*)channel->buf;
                channel->packetSize=ntohl(tmp);
            }
               return readData(channel);

        }

    }
    else
    {
        ret=read(channel->fd,channel->buf+channel->readSize,channel->packetSize+4-channel->readSize);
        if(ret>0)
        {
            channel->readSize+=ret;
            if(channel->readSize==channel->packetSize+4)
                return channel;
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

void handleData(Channel*channel)
{
    channel->readSize=0;//不要忘记清零
    channel->buf[channel->readSize]=0;
    printf("%s\n",channel->buf+4);
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
            handleData(channel);

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
    init();
    exec();

    return 0;
}
