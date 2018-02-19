#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    //创建套接字
    int fd=socket(AF_INET,SOCK_STREAM,0);

    //设置结诟体，用来绑定IP和端口
    struct sockaddr_in addr;
    addr.sin_addr.s_addr=inet_addr("0.0.0.0");
    addr.sin_family=AF_INET;
    addr.sin_port=htons(23999);    
    
    //绑定地址端口信息到socket文件
    bind(fd,(struct sockaddr*)&addr,sizeof(addr));

    //监听
    listen(fd,10);//同时监听10个客户端
    int newfd=accept(fd,NULL,NULL);//创建服务器和客户端之间通信的文件
    if(newfd<0)
    {
        printf("communication fails.\n");
        return;
    }
    //读客户端的文件信息
    char buf[1024];
    memset(buf,0,sizeof(buf));

    int ret=read(newfd,buf,sizeof(buf));
    if(ret>0)
    {
        printf("buf=%s\n",buf);
        //向客户端写信息
        char *ptr="ABC";
        write(newfd,ptr,strlen(ptr));
    }else
    {
        perror("ret:");
    }
    
    return 0;

}
