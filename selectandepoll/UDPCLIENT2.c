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
    addr.sin_addr.s_addr=inet_addr("255.255.255.255");

    struct sockaddr_in addr1;
    addr1.sin_family=AF_INET;
    addr1.sin_port=htons(9988);
    addr1.sin_addr.s_addr=inet_addr("192.168.19.101");
    bind(fd,(struct sockaddr*)&addr1,sizeof(addr1));    
    int v=1;
    setsockopt(fd,SOL_SOCKET,SO_BROADCAST,&v,sizeof(v));
    
    printf("before sendto\n");
    sendto(fd,"hello world",11,0,
            (struct sockaddr*)&addr,sizeof(addr)
            );
    
    char buf[1024];
    memset(buf,0,sizeof(buf));
    read(fd,buf,sizeof(buf));
    printf("%s\n",buf);
    return 0;
}
