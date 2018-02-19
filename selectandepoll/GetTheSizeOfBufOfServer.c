#include"../header.h"
#include<netinet/in.h>
//获得服务器端发送端及输出端的缓冲区大小

int main()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in addr;

    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=INADDR_ANY;
//    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(23999);

    bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    getchar();
    printf("start listen]\n");
    listen(fd,10);

    int newfd=accept(fd,NULL,NULL);
    if(newfd<0)
    {
        perror("accept");
        return 0;
    }

    int  bufsize=0;
    socklen_t argsize=sizeof(bufsize);
    getsockopt(newfd,SOL_SOCKET,SO_RCVBUF,&bufsize,&argsize);
    printf("recv bufsize is %d\n",bufsize);
    
    getsockopt(newfd,SOL_SOCKET,SO_SNDBUF,&bufsize,&argsize);
    printf("send bufsize is %d\n",bufsize);
    char buf[1024];
    memset(buf,0,sizeof(buf));
    read(newfd,buf,sizeof(buf));

    printf("buf=%s\n",buf);
    
    close(newfd);
    close(fd);
    return 0;
}
