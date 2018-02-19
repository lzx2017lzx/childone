#include"NETWORK.h"
//本客户端模拟发送广播，注意要和客户端绑定的地址0.0.0.0是不会被绑定成功
//的，即使换了另一个地址，也不会成功绑定成功。但是这不会影响广播功能
//但是千万不要将return 0填上，不要以为绑定不成功，程序就退出啦
int main()
{
    int fd=socket(AF_INET,SOCK_DGRAM,0);
    if(fd<0)
    {
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9988);
    addr.sin_addr.s_addr=inet_addr("255.255.255.255");
    struct sockaddr_in addrmyself;
    addrmyself.sin_family=AF_INET;
    addrmyself.sin_port=htons(9988);
    addrmyself.sin_addr.s_addr=inet_addr("0.0.0.0");
    int ret=bind(fd,(struct sockaddr*)&addrmyself,sizeof(addrmyself));
    printf("ret=%d",ret);
    if(ret<0)
    {
        perror("ret:");
//        return 0;
    }
    int arg=1;
    setsockopt(fd,SOL_SOCKET,SO_BROADCAST,&arg,sizeof(arg));

    sendto(fd,"hello world",11,0,(struct sockaddr*)&addr,sizeof(addr));
    printf("sendto fini\n");
    char buf[1024];
    memset(buf,0,sizeof(buf));
    printf("%s\n",buf);
    return 0;
}
