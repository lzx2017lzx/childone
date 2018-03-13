#include <iostream>
#include<string>
#include <fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main01(int argc, char *argv[])
{
    fstream File("text.txt",ios::in | ios::out);

    File << "Hi!"; //将“Hi!”写入文件   
    static char str[10]; //当使用static时，数组会自动被初始化
    //即是被清空为零


    File.seekg(ios::beg); // 回到文件首部
    // 此函数将在后面解释
    File >> str;
    cout << str << endl;

    File.close();

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

int main(int argc, char *argv[])
{
    ifstream OpenFile("text.txt");
    ofstream SaveFile("file1.txt", ios::ate);
    char src[1024];  
    char dst[1024];
    while(!OpenFile.eof()){
    src[0]='\0';
    dst[0]='\0';
    OpenFile.getline(src,80);
    cout<<"src:"<<src<<endl; //注意结束条件的判断  
    handleLine(src,dst,"Hi","hi");
    strcat(dst,"\n");
    SaveFile<<dst;
    }  
    OpenFile.close();
    SaveFile.close();

    return 0;
}
