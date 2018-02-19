#include"../header.h"

int main()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9977);
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");


    int ret=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret<0)
    {
        perror("bind");
        return -1;
    }

    listen(fd,250);
    while(1)
    {
        char buf[4096];
        printf("before accept\n");
    int newfd=accept(fd,NULL,NULL);
    printf("after accept\n");
    if(newfd<0)
    {
        if(errno==EINTR)continue;
        break;
    }
    int filefd=open("a",O_WRONLY|O_CREAT|O_TRUNC,0777);
    
    while(1)
    {
        int ret=read(newfd,buf,sizeof(buf));
        if(ret==0)
        {
            printf("peer close socket\n");
            break;
        }
        if(ret==-1&&errno==EINTR)continue;
        if(ret==-1)
        {
            perror("read");
            break;
        }
    write(filefd,buf,ret);
    }
    
    close(newfd);
    close(filefd);
    }
    close(fd);
}
