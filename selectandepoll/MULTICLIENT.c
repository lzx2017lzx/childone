#include"../header.h"
#include<netinet/in.h>

void forkn(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        pid_t pid=fork();
        if(pid==0)break;


    }

}
//多进程模拟多个客户端
int main()
{
    forkn(10);
    int fd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(9988);

    connect(fd,(struct sockaddr*)&addr,sizeof(addr));
    
    write(fd,"hello world",11);
    printf("hello world\n");
    close(fd);
    return 0;
}
