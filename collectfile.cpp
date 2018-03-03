#include<sys/types.h>
#include<sys/mman.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/mman.h>
#include<utime.h>
#include<dirent.h>
#include<string>
#include<iostream>
using namespace std;
char dstdir[1024];

void getFileSuffix(const char *filename,char * suffix)
{
    char *q=(char*)filename;
    char *k=(char*)filename;
    while(*q!='\0')
    {
        q++;
    }

    k=q;
    while(*k!='/') k--;
    k++;
    strcat(suffix,k);
}
void cpfile(const char * srcfilename)
{
    char dstfilename[1024]={0};
    strcpy(dstfilename,dstdir);
    getFileSuffix(srcfilename,dstfilename);
    
    int fd_src=open(srcfilename,O_RDONLY);
    if(fd_src<0)
    {
        printf("srcfilename:%s\n",srcfilename);
        perror("open src");
        return;
    }
    int fd_dst=open(dstfilename,O_WRONLY|O_CREAT|O_EXCL,0777);
    if(fd_dst<0)
    {
        fd_dst=open(dstfilename,O_WRONLY|O_TRUNC);
        if(fd_dst<0)
        {
            printf("dstfilename:%s\n",dstfilename);
            perror("open dst");
            return;
        }
    }

    char buf[4096];

    while(1)
    {
        int readlen=read(fd_src,buf,sizeof(buf));
        if(readlen==0)
        {
            break;
        }
        write(fd_dst,buf,readlen);
    }
    close(fd_src);
    close(fd_dst);
}

void tar_dir(string srcname,int *pcount)
{
    DIR *dir=opendir(srcname.c_str());//如果是文件不是目录，是否要考虑判断dir是不是NULL
    if(dir==NULL)
        return;
    struct dirent * pdir=readdir(dir);
    while(1)
    {

        if(pdir==NULL)
        {
            break;
        }
        if(pdir->d_type==DT_REG)
        {
            
            cpfile((srcname+"/"+pdir->d_name).c_str());
            (*pcount)++;
        }else if(pdir->d_type==DT_DIR)
        {
            if((strcmp(pdir->d_name,".")!=0)&&((strcmp(pdir->d_name,"..")!=0)))//如果不判断会进入死循环
            {
                tar_dir(srcname+"/"+pdir->d_name,pcount);
            }
        }
        pdir=readdir(dir);
    }
    closedir(dir);
}

int main(int argc,char *argv[])
{
    int status=0;
    if(argc<3)
    {
        printf("USAGES:[exec] [src] [dstdir/]\n");
        return -1;
    }
    const char *src_file=argv[1];
    strcpy(dstdir,argv[2]);
    
    status=mkdir(dstdir,0777);
    if(status==-1)
    {
        perror("mkdir error");
    }
    int count=0;
    tar_dir(src_file,&count); 
    printf("count=%d\n",count);
}
