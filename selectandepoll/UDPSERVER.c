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
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    int ret=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret<0)return -1;

    char buf[4096];
    memset(buf,0,sizeof(buf));
    read(fd,buf,sizeof(buf));
    
    printf("%s\n",buf);


















}
