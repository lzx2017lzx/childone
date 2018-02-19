#include"../header.h"
#include<netinet/in.h>
int main()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("192.168.15.137");
    addr.sin_port=htons(23999);

    connect(fd,(struct sockaddr*)&addr,sizeof(addr));
    
    write(fd,"hello world",11);

    return 0;
}
