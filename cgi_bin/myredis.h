#ifndef _MYREDIS_H
#define _MYREDIS_H
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
//	cout<<"ctx:"<<ctx;
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
//		cout<<"getSet ret is null";
		return lisstr;
	}

//	cout<<"getset return "<<ret->type;
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
//		cout<<"ret->str:";
		if(ret)
			freeReplyObject(ret);
		itkeys++;
		itvalues++;
	}
//	cout<<"afterredisCommad addHash."<<endl;
	updateExpire(name,timeout);
	return 0;
}





void Redis::updateExpire(string name,int timeout)
{
	redisReply*ret=(redisReply*)redisCommand(ctx,"expire %s %d",name.c_str(),timeout);
	if(ret)
		freeReplyObject(ret);

}

#endif
