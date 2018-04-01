#include <iostream>
#include<string>
#include <fstream>
#include<cstring>
#include<cstdlib>
#include<unistd.h>
#include<vector>
using namespace std;
void  handleLine(const char *,char *,bool &);

vector<string>filestring;

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        cout<<"USAGE:EXEFILE SRCFILENAME"<<endl;
        return -1;
    }
    fstream OpenFile(argv[1],ios::in | ios::out);

    char src[1024];  
    char dst[1024];
    bool status=false;

    while(!OpenFile.eof()){

        src[0]='\0';
        dst[0]='\0';
//        memset(src,0,1024);
//        memset(dst,0,1024);
        OpenFile.getline(src,1024);
        std::cout<<"src:"<<string(src)<<std::endl;
        handleLine(src,dst,status);
        strcat(dst,"\n");
        filestring.push_back(string(dst));
    }  


    OpenFile.close();

    fstream WriteOpenFile(argv[1],ios::out | ios::trunc);
    for(vector<string>::iterator it=filestring.begin();it!=filestring.end();++it)
    {
        WriteOpenFile<<(*it);    
    }

    WriteOpenFile.close();
    return 0;
}

// status==true,in notation state
void  handleLine(const char * src,char * dst,bool &status)
{
    char * startptr=const_cast<char*>(src);
    char * ptrone=NULL;
    char c=0;
    while(c=*startptr)
    {
        if((!status)&&((c!='/')||((c=='/')&&(*(startptr+1)!='*'))))
        {
            *dst++=*startptr++;    
            printf("*dst:%c\n",*(dst-1));
        }
        else if(!status)
        {
            startptr++;
            status=true;
        }else if(status&&(c!='*'||(c=='*'&&*(startptr+1)!='/')))
        {
            startptr++;
        }else
        {
            status=false;// means end of notation
            startptr++;
            startptr++; // jump * and /
        }
    }
    *dst='\0';

    printf("dst in handleLine:%s\n",dst);

}

