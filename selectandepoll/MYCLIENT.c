#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    //建立socket文件
    int cl=socket(AF_INET,SOCK_STREAM,0);

    //建立绑定套接字的地址
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(23999);

    //连接socket文件和套接字
    if(connect(cl,(struct sockaddr*)&addr,sizeof(addr))==-1)
    {
        perror("connect");
    }

    char *ptr="我是客户端";
    write(cl,ptr,strlen(ptr));

    char buf[1024];
    memset(buf,0,sizeof(buf));
    read(cl,buf,sizeof(buf));
    printf("buf=%s\n",buf);
    return 0;
}
