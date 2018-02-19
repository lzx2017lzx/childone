#include"../header.h"
#include<netinet/in.h>
//本服务器和客户端只使用了传输层协议，报文没有经过数据链路层。

int main()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in addr;

    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("192.168.15.137");
    addr.sin_port=htons(23999);

    bind(fd,(struct sockaddr*)&addr,sizeof(addr));

    listen(fd,10);

    int newfd=accept(fd,NULL,NULL);

    char buf[1024];
    memset(buf,0,sizeof(buf));
    read(newfd,buf,sizeof(buf));

    printf("buf=%s\n",buf);
    
    close(newfd);
    close(fd);
    return 0;
}
