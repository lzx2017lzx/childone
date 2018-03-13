#include <iostream>
#include<string>
#include <fstream>
#include<cstring>
#include<cstdlib>
#include<unistd.h>
using namespace std;
void  handleLine(const char * src,char * dst,const char *tgt,const char *cgd);

int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        cout<<"USAGE:EXE SRC DST"<<endl;
        return -1;
    }
    fstream OpenFile("onefiledes.txt",ios::in | ios::out);
    
    char src[1024];  
    char dst[1024];
    int i=0;

    OpenFile.seekg(0);
    bool flag=false;
    while(!OpenFile.eof()){
    i=OpenFile.tellg();

    src[0]='\0';
    dst[0]='\0';
    OpenFile.getline(src,80);
    OpenFile.seekg(i);
    handleLine(src,dst,argv[1],argv[2]);
    strcat(dst,"\n");
    OpenFile<<dst;
    if(i==-1)
    {
    cout<<"OpenFile:"<<OpenFile.rdstate()<<endl;
    cout<<"ios::godbit:"<<(int)ios::goodbit<<endl;
    cout<<"ios::eofbit:"<<(int)ios::eofbit<<endl;
    cout<<"ios::failbit:"<<(int)ios::failbit<<endl;
    cout<<"ios::badbit:"<<(int)ios::badbit<<endl;

    break;
    }
    }  
    OpenFile.close();

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

