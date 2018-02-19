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


    sendto(fd,"hello world",11,0,
            (struct sockaddr*)&addr,sizeof(addr)
            );


}
