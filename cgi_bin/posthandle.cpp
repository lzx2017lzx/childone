#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

extern char**environ;

int main()
{
	cout<<"Content-type:text/html\r\n\r\n";
	if(strcmp(getenv("REQUEST_METHOD"),"POST")==0)
	{
		int content_length=atoi(getenv("CONTENT_LENGTH"));
		char * buf=(char *)malloc(content_length+1);
		buf[content_length]=0;
		
		fread(buf,content_length,1,stdin);
		char * arg=buf;
		strtok(arg,"=&");
		char * user=strtok(NULL,"=&");
		strtok(NULL,"=&");
		char * pass=strtok(NULL,"=&");
		printf("username is %s password is %s",user,pass);
	free(buf);


	}


	return 0;
}
