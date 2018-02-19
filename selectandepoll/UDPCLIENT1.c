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
    addr.sin_addr.s_addr=inet_addr("192.168.15.137");
    struct sockaddr_in addrmyself;
    addrmyself.sin_family=AF_INET;
    addrmyself.sin_port=htons(9988);
    addrmyself.sin_addr.s_addr=inet_addr("192.168.19.101");
    int ret=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    printf("ret=%d",ret);
    if(ret<0)
    {
        perror("ret:");
        return 0;
    }
    sendto(fd,"hello world",11,0,
            (struct sockaddr*)&addrmyself,sizeof(addrmyself)
          );

    char buf[1024];
    memset(buf,0,sizeof(buf));
    printf("%s\n",buf);
    return 0;
}
