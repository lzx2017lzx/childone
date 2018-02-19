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
template<class T>
T stringtonumber(const string &str)//如果不加const 形参是匿名对象不会成功传参
{
	std::stringstream ss(str);
	T number;
	ss>>number;
	return number;
}

int getnearbydrivers(const char*postbuf)
{
	//从json报文中提取信息
	Json resp;
	resp.parse(postbuf);
	string username=resp.getString("username");
	double lat=resp.getDouble("lat");
	double lng=resp.getDouble("lng");
	int geohash=resp.getInt("geohash");

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
    for(;it1!=drivers.end();it1++)
    {
	    Json driver;
	    driver.add("name",*it1);
	    double lat=stringtonumber<double>(redis.getHashMember(*it1,"lat"));
	    driver.add("lat",lat);
	    double lng=stringtonumber<double>(redis.getHashMember(*it1,"lng"));
	    driver.add("lng",lng);
	    driver.getroot();
	    driversjsonarray.addarray(driver.getroot());

	    driverCount++;
	    if(driverCount>=10)
		    break;
    }

    if(driverCount>=10)
	    break;
	}
	//printf("dirvers:%s\n",driversjsonarray.print());
	Json respagain;
	respagain.add("drivers",driversjsonarray.getJsonArray());
	respagain.add("response","ok");
	printf("%s",respagain.print());
	return 0;	
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
#if 0
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
		getnearbydrivers(buf);

		free(buf);


	}

	return 0;
}
