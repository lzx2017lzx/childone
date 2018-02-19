#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
int main()
{
    int fdp=socket(AF_INET,SOCK_DGRAM,0);

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9988);
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");

    bind(fdp,(struct sockaddr*)&addr,sizeof(addr));


    char buf[4096];
    memset(buf,0,sizeof(buf));
    
    struct sockaddr peeraddr;
   // read(fdp,buf,sizeof(buf));
    socklen_t peerlen=sizeof(peeraddr);
    recvfrom(fdp,buf,sizeof(buf),0,&peeraddr,&peerlen);
    printf("buf=%s\n",buf);
    sendto(fdp,"world",5,0,&peeraddr,sizeof(peeraddr));
    return 0;
}
