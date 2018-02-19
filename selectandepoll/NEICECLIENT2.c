#include"../header.h"
#include<netinet/in.h>
int main()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(9988);

   if(connect(fd,(struct sockaddr*)&addr,sizeof(addr))==-1)
       
   {
       perror("connect");
   }
    
    write(fd,"hello world",11);

    return 0;
}
