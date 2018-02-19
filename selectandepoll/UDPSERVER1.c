#include"NETWORK.h"

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
    addr.sin_addr.s_addr=inet_addr("192.168.19.101");
    int ret=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret<0)return -1;

    char buf[4096];
    memset(buf,0,sizeof(buf));
   // read(fd,buf,sizeof(buf));
    struct sockaddr peer_addr;
    socklen_t addrlen=sizeof(peer_addr);

    printf("%d\n",(int)addrlen);
    recvfrom(fd,buf,sizeof(buf),0,&peer_addr,&addrlen);//其中addrlen即做传入参数又做传出参数

    printf("99\n");

    return 0;

}
