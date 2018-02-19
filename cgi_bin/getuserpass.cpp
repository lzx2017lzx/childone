#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include"mysqllib.h"
#include"opensslmd5API.h"
#include"json.h"
extern char**environ;
int registeruser(string username,string password)
{
//	printf("username:%s\n",username.c_str());
//	printf("password:%s\n",password.c_str());

	char sqlcommand[1024]={0};
	const char *passwordtemp=MYMD5((const char*)password.c_str());
//	printf("passwordtemp:%s\n",passwordtemp);
	sprintf(sqlcommand, "select * from tuser where username = '%s' and fpassword = '%s';", username.c_str(), passwordtemp);
//	printf("sqlcommand:%s\n",sqlcommand);
	char charreturn[4096]={0};
	char chartemp[4096]={0};

	mysqllib *mysql = mysqllib::getInstance();
//	printf("mysql:");
	if(mysql->select(sqlcommand))
	{
		//数据库中不存在该人员,插入数据，执行注册程序
		strcpy(charreturn,"register failed");
//		printf("charreturn:%s\n",charreturn);
		memset(sqlcommand,0,sizeof(sqlcommand));
		sprintf(sqlcommand, "insert into tuser(username,fpassword) values('%s','%s')", username.c_str(), passwordtemp);
		if(mysql->insert(sqlcommand))
		{
			strcpy(charreturn,"register failed");
//			printf("charreturn:%s\n",charreturn);
//			printf("query error\n");
			Json res;
			res.add("response",charreturn);
			strcpy(chartemp,res.print());
			printf("%s",chartemp);
			return -2;

		};
		strcpy(charreturn,"register success");
//		printf("charreturn:%s\n",charreturn);
		Json res;
		res.add("response",charreturn);
		strcpy(chartemp,res.print());
		printf("%s",res.print());
		return 0;

	}else
	{
		strcpy(charreturn,"you are already registed.\n");
//		printf("charreturn:%s\n",charreturn);
		Json res;
		res.add("response",charreturn);
		strcpy(chartemp,res.print());
		printf("%s",chartemp);
		return 0;
	}

}

int main()
{
	printf("Content-type:text/html\r\n\r\n");

	int i;
	char *arg=getenv("QUERY_STRING");
	strtok(arg,"=&");
	char *user=strtok(NULL,"=&");
	strtok(NULL,"=&");
	char *pass=strtok(NULL,"=&");
//	printf("username is %s password is %s",user,pass);
	string userstr(user);
	string passstr(pass);
//	string userstr("test1");
//	string passstr("test1");
	if((user!=NULL)&&(pass!=NULL))
	registeruser(userstr,passstr);
	
	return 0;
}
