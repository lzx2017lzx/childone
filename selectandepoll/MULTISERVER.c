#include"NETWORK.h"
#include<signal.h>
void handle(int v)
{
    if(v==SIGCHLD)
    {
        while(1)
        {
            pid_t pid=waitpid(-1,NULL,WNOHANG);
            if(pid<=0)break;
        }
    }
}
//多进程服务器
int main()
{
//    signal(SIGCHLD,handle);
    uint16_t port=9988;
    int server=myServer(port,"0.0.0.0");

    while(1)
    {
        int newfd=myAccept(server,NULL,NULL);
        
        pid_t pid=fork();
        if(pid==0)
        {
            close(server);
            char buf[1024];
            memcpy(buf,0,sizeof(buf));
            read(newfd,buf,sizeof(buf));
            printf("%s,%d\n",buf,newfd);
            return 0;
        }


        close(newfd);
    }
}











