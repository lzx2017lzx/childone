#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"mysqllib.h"
#include"opensslmd5API.h"
#include"json.h"
#include"myredis.h"
using namespace std;

extern char**environ;
int handleredis(const char *postbuf)
{
	//解包
	Json resp;
	string temp(postbuf);
	resp.parse(temp);
	string username=resp.getString("username");
	string password=resp.getString("password");
	string type=resp.getString("type");
	double lat=resp.getDouble("lat");
	double lng=resp.getDouble("lng");
	int geohash=resp.getInt("geohash");

	Redis redis;
	redis.addSet(type,username);
	if(redis.addSet(type,username)!=0)
	{
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
	lisstrvalue.push_back(tempstr);	
	if(redis.addHash(username,lisstrkey,lisstrvalue))
	{
		return -1;
	};

	if(type=="d")
	{

		if(redis.addSet(tempstr,username))
			return -2;
	}

	return 0;
}

int loginuser(string username,string password,const char*postbuf)
{

	char sqlcommand[1024]={0};
	const char *passwordtemp=MYMD5((const char*)password.c_str());
	sprintf(sqlcommand, "select * from tuser where username = '%s' and fpassword = '%s';", username.c_str(), passwordtemp);
	char charreturn[4096]={0};
	char chartemp[4096]={0};
	Json res;

	mysqllib *mysql = mysqllib::getInstance();
	if(mysql->select(sqlcommand))
	{
		//数据库中不存在该人员，登录失败
		strcpy(charreturn,"login failed");
		memset(sqlcommand,0,sizeof(sqlcommand));
		res.add("response",charreturn);
		strcpy(chartemp,res.print());
		printf("%s",res.print());
		return -1;
	}else
	{
		strcpy(charreturn,"login success");
		res.add("response",charreturn);
		int ret=handleredis(postbuf);
		if(ret==0)
		{
			strcat(charreturn,"handlerredis is ok");
			res.add("storedatas","ok");
		}else
		{
			strcat(charreturn,"but handlerredis is not ok");
			res.add("storedatas","fail");
		}
		strcpy(chartemp,res.print());
		printf("%s",chartemp);
		return 0;
	}
}

int main()
{
	cout<<"Content-type:text/html\r\n\r\n";
	if(strcmp(getenv("REQUEST_METHOD"),"POST")==0)
	{
		int content_length=atoi(getenv("CONTENT_LENGTH"));
		char * buf=(char *)malloc(content_length+1);
		buf[content_length]=0;
		
		fread(buf,content_length,1,stdin);
#if 1
	Json postjson;
	string temp(buf);
	postjson.parse(temp);
	string username=postjson.getString("username");
	string password=postjson.getString("password");
	if((username.size()!=0)&&(password.size()!=0))
#endif

#if 0
	Json root;
        root.add("username",string("heihei"));
        root.add("password",string("heihei"));
        root.add("type","d");
        root.add("cmd","login");
        root.add("lat",34.1110);
        root.add("lng",68.2220);
        root.add("geohash",98764);
#endif
	
	//loginuser(username,password,root.print());	
	loginuser(username,password,buf);	
	free(buf);


	}

	return 0;
}
