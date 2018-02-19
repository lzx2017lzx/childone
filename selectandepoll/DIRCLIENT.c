#include"NETWORK.h"

int sendFile(const char *dst,const char *src,int fd)
{
    myWrite(fd,"r",1);
    printf("sendfile before mywritelen fd strlen(dst)\n");
    myWriteLen(fd,strlen(dst));
    printf("sendfile after mywritelen fd strlen(dst)\n");
    myWrite(fd,(char *)dst,strlen(dst));
    printf("sendfile after mywritele fd dst strlen(dst)\n");
    
    myWriteLen(fd,myFileSize(src));
    printf("sendfile after mywritelen\n");
    int filefd=open(src,O_RDONLY);
    char buf[4095];
    while(1)
    {
        int ret=read(filefd,buf,sizeof(buf));
        printf("read ret=%d\n",ret);
        if(ret==0)break;
        if(ret<0)
        {
            printf("ret=%d\n",ret);
            perror("ret:");
            break;
        }
        myWrite(fd,buf,ret);

    }
    
    close(filefd);


}


int sendDir(const char *dst,const char *src,int fd)
{
    myWrite(fd,"d",1);
    myWriteLen(fd,strlen(dst));
    myWrite(fd,(char *)dst,strlen(dst));
            char *bufDst=malloc(1024);
            char *bufSrc=malloc(1024);

    DIR*dir=opendir(src);
    struct dirent*entry;
    do
   
    {
        printf("do while in\n");
        entry=readdir(dir);
        printf("readdir\n");
        if(entry==NULL)
            break;
        if(entry->d_name[0]=='.')continue;
            sprintf(bufDst,"%s/%s",dst,entry->d_name);
            sprintf(bufSrc,"%s/%s",src,entry->d_name);

        if(entry->d_type==DT_REG)
        {
        printf("before sendifle in\n");
            sendFile(bufDst,bufSrc,fd);
        printf("after sendifle in\n");

        }else if(entry->d_type==DT_DIR)
        {

        printf("before senddir in\n");
           sendDir(bufDst,bufSrc,fd); 
        printf("after senddir in\n");
        }
    }while(1);  

    free(bufDst);
    free(bufSrc);
    closedir(dir);
    return 0;
}
int main(int argc,char *argv[])
{
    const char*src=argv[1];
    const char*dst=argv[2];
    const char *ip=argv[3];
    const char *port=argv[4];
    printf("cl69\n");
    int fd=socket(AF_INET,SOCK_STREAM,0);
    printf("cl71\n");
    int ret=myConnect(fd,atoi(port),ip);
    printf("cl73\n");

    if(ret<0)
    {
        return -1;
    }

    sendDir(dst,src,fd);
    
    myWrite(fd,"x",1);







}



