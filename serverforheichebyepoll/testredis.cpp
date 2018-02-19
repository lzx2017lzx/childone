#include<iostream>
#include<hiredis/hiredis.h>
#include<string>
#include<list>
#include<sstream>
using namespace std;

class Redis
{
	public:
		Redis();
		~Redis();
		int addSet(string set,string value);
		list<string> getSet(string set);
		string getHashMember(string name,string keyname);
		int addHash(string name,list<string> keys,list<string> values,int timeout=100000);
		void updateExpire(string name,int timeout);
	private:
		redisContext*ctx;
		list<string>strlis;

};

Redis::Redis()
{
	ctx=redisConnect("127.0.0.1",6379);
	cout<<"ctx:"<<ctx;
}

Redis::~Redis()
{
	redisFree(ctx);
}

int Redis::addSet(string set,string value)
{
	string cmd=string("sadd "+set+" "+value);
	redisReply*ret=(redisReply*)redisCommand(ctx,cmd.c_str());
	if(ret==NULL)
	{
		return -1;
	}

	freeReplyObject(ret);
	return 0;
}

list<string> Redis::getSet(string set)
{
	list<string> lisstr;
	redisReply*ret=(redisReply*)redisCommand(ctx,"smembers %s",set.c_str());

	if(ret==NULL)
	{
		cout<<"getSet ret is null";
		return lisstr;
	}

	cout<<"getset return "<<ret->type;
	if(ret->type==REDIS_REPLY_ARRAY)
	{
		for(int i=0;i<ret->elements;++i)
		{
			redisReply*r=ret->element[i];
			lisstr.push_back(r->str);

		}

	}
	return lisstr;
}

string Redis::getHashMember(string name,string keyname)
{
	string str;
	redisReply*ret=(redisReply*)redisCommand(ctx,"hget %s %s",name.c_str(),keyname.c_str());
	if(ret->type==REDIS_REPLY_INTEGER)
	{
		std::stringstream ss;
		ss<<ret->integer;
		ss>>str;
	}else
		str=ret->str;
	if(ret)
		freeReplyObject(ret);
	return str;
}

int Redis::addHash(string name,list<string> keys,list<string> values,int timeout)
{
	int count=keys.size();
	if(values.size()<count)
		return -1;

	list<string>::iterator itkeys=keys.begin();
	list<string>::iterator itvalues=values.begin();
	for(int i=0;i<count;i++)
	{
		string key=*itkeys;
		string value=*itvalues;

		redisReply*ret=(redisReply*)redisCommand(ctx,"hset %s %s %s",name.c_str(),key.c_str(),value.c_str());
		cout<<"ret->str:";
		if(ret)
			freeReplyObject(ret);
		itkeys++;
		itvalues++;
	}

	updateExpire(name,timeout);
	return 0;
}





void Redis::updateExpire(string name,int timeout)
{
	redisReply*ret=(redisReply*)redisCommand(ctx,"expire %s %d",name.c_str(),timeout);
	if(ret)
		freeReplyObject(ret);

}


int main()
{

	Redis redis;
	redis.addSet(string("hello"),string("world"));
	list<string>lisstrkey;
	lisstrkey.push_back("status");
	lisstrkey.push_back("lat");
	lisstrkey.push_back("lng");
	lisstrkey.push_back("type");
	lisstrkey.push_back("geohash");

	list<string>lisstrvalue;
	lisstrvalue.push_back("0");
	std::stringstream ss;
	ss<<90.111;
	string temp;
	ss>>temp;
	lisstrvalue.push_back(temp);
	ss<<120.133;
	ss>>temp;
	lisstrvalue.push_back(temp);
	lisstrvalue.push_back("driver");
	lisstrvalue.push_back("111100000");


	redis.addHash(string("lihua"),lisstrkey,lisstrvalue);

	list<string>lisstrgetset;
	lisstrgetset=redis.getSet(string("hello"));
	cout<<endl;

	list<string>::iterator itgetset=lisstrgetset.begin();
	cout<<"lisstrgetset:"<<lisstrgetset.size()<<endl;

	for(int i=0;i<lisstrgetset.size();i++)
	{
		cout<<*itgetset<<endl;
		itgetset++;
	}

	string strgethashmem=redis.getHashMember(string("lihua"),"lat");
	cout<<"strgethashmem:"<<strgethashmem<<endl;

	return 0;
}
