#include <iostream>
#include<string>
#include <fstream>
#include<cstring>
#include<cstdlib>
#include<unistd.h>
#include<vector>
using namespace std;
void  handleLine(const char * src,char * dst,const char *tgt,const char *cgd);

vector<string>filestring;

int main(int argc, char *argv[])
{
    if(argc!=4)
    {
        cout<<"USAGE:EXEFILE SRCFILENAME SRCSTRING DSTSTRING"<<endl;
        return -1;
    }
    fstream OpenFile(argv[1],ios::in | ios::out);
    
    char src[1024];  
    char dst[1024];

    while(!OpenFile.eof()){

    src[0]='\0';
    dst[0]='\0';
    OpenFile.getline(src,1024);
    handleLine(src,dst,argv[2],argv[3]);
    strcat(dst,"\n");
    filestring.push_back(string(dst));
    }  


    OpenFile.close();

    fstream WriteOpenFile(argv[1],ios::out | ios::trunc);
    for(vector<string>::iterator it=filestring.begin();it!=filestring.end();++it)
    {
        WriteOpenFile<<(*it);    
        cout<<"*it:"<<(*it);
    }

    WriteOpenFile.close();
    return 0;
}


void  handleLine(const char * src,char * dst,const char *tgt,const char *cgd)
{
    char * startptr=(char*)src;
    char * ptrone=NULL;

    while((ptrone=strstr(startptr,tgt))!=NULL)
    {
        
        strncat(dst,startptr,ptrone-startptr);
        strcat(dst,cgd);
        startptr=ptrone+strlen(tgt);
    }

    if(startptr!=NULL)
    {
        strcat(dst,startptr);
    }

}

