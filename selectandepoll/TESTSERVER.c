
#include"NETWORK.h"


int main()
{
    int server=myServer(9988,"0.0.0.0");
    int newfd=myAccept(server,NULL,NULL);
    char buf[1024];
    memset(buf,0,sizeof(buf));

    int ret=read(newfd,buf,sizeof(buf));
    printf("buf=%s\n",buf);
    sleep(1000000);



    return 0;
}
