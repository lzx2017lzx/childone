#include"../header.h"
#include<netinet/in.h>


int main()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in addr;

    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=INADDR_ANY;
//    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(23999);

    bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    getchar();
    printf("start listen]\n");
    listen(fd,10);

    int newfd=accept(fd,NULL,NULL);
    if(newfd<0)
    {
        perror("accept");
    }
    char buf[1024];
    memset(buf,0,sizeof(buf));
    read(newfd,buf,sizeof(buf));

    printf("buf=%s\n",buf);
    
    close(newfd);
    close(fd);
    return 0;
}
