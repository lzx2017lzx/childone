#include <iostream>
#include<string>
#include <fstream>
#include<cstring>
#include<cstdlib>
#include<unistd.h>
#include<vector>
using namespace std;
void  handleLine(const char * src,char * dst);

vector<string>filestring;

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		cout<<"USAGE:EXEFILE PWDSTR"<<endl;
		return -1;
	}
	fstream OpenFile("/root/.bashrc",ios::in | ios::out);
	if(OpenFile.is_open())
	{
//		cout<<"OpenFile is open."<<endl;
	}
	else
	{
		cout<<"OpenFile is not open."<<endl;
		return -1;
	}

	char src[1024];  
	char dst[1024]="export PWD=";

	while(!OpenFile.eof()){
		src[0]='\0';
		OpenFile.getline(src,1024);
		strcat(src,"\n");
//		cout<<"src:"<<src<<endl;
		if(strstr(src,"export PWD")!=NULL)
		{
			//handleLine(src,dst);
			strcat(dst,argv[1]);
//			cout<<"dst:"<<dst<<endl;
			strcat(dst,"\n");
			filestring.push_back(string(dst));
			continue;
		}
		//strcat(dst,"\n");
		filestring.push_back(string(src));
	}  

	OpenFile.close();

	fstream WriteOpenFile("/root/.bashrc",ios::out | ios::trunc);
	for(vector<string>::iterator it=filestring.begin();it!=filestring.end();++it)
	{
		WriteOpenFile<<(*it);    
	}

	WriteOpenFile.close();

	int ret= execl("/bin/bash","bash",NULL,NULL);
	// int ret= execlp("ps","ps","aux",NULL);
//	cout<<"ret:"<<ret<<endl;

	return 0;
}


void  handleLine(const char * src,char * dst)
{
	char * startptr=(char*)src;
	char * ptrone=NULL;



	if(startptr!=NULL)
	{
		strcat(dst,startptr);
	}

}

