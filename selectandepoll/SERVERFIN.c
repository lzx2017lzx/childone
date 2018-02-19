

#include"NETWORK.h"

int main()
{
    int server=myServer(9988,"127.0.0.1");
    if(server==-1)
    {
        printf("create server error\n");
        return -1;
    }

    while(1)
    {
        int fd=myAccept(server,NULL,NULL);

        if(fd<0)
        {
            printf("accept error\n");
            return -1;
        }    

        int filefd=open("a",O_WRONLY|O_TRUNC|O_CREAT,0777);

        char buf[4096];
        while(1)
        {
            int ret=myRead2(fd,buf,sizeof(buf));
            if(ret>0)
            {
                write(filefd,buf,ret);
            }
            else
            {
                break;
            }
        }
        close(filefd);
        close(fd);
    }
    close(server);
}

