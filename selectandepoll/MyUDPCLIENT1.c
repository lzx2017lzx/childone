#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
//#include<sys/un.h>
int main()
{
    int fd=socket(AF_INET,SOCK_DGRAM,0);

   struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9988);
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    
    connect(fd,(struct sockaddr*)&addr,sizeof(addr));
//    sendto(fd,"hello",5,0,(struct sockaddr*)&addr,sizeof(addr));
    write(fd,"hello",5);


    char buf[4096];
    memset(buf,0,sizeof(buf));
    //    read(fd,buf,sizeof(buf));
    socklen_t socklen=sizeof(addr);
    //recvfrom(fd,buf,sizeof(buf),1,(struct sockaddr*)&addr,&socklen);
        read(fd,buf,sizeof(buf));
    printf("buf=%s",buf);


    return 0;
}
