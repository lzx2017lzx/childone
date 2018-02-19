#include"header.h"
int main()
{
    int epollfd=epoll_create(512);

    int fd_key=open("/dev/input/event1",O_RDONLY);
    int fd_mice=open("/dev/input/mice",O_RDONLY);

    struct epoll_event ev;
    ev.data.fd=fd_key;
    ev.events=EPOLLIN;//监控可读
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd_key,&ev);

    ev.data.fd=fd_mice;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd_mice,&ev);

    struct epoll_event evout[2];
    char buf[1024];
    while(1)
    {
        int ret=epoll_wait(epollfd,evout,2,5000);
        if(ret==0)
        {
            continue;
        }

        if(ret<0&&errno==EINTR)continue;
        if(ret<0)break;

        int i=0;
        for(i=0;i<ret;++i)
        {
            int fd=evout[i].data.fd;
            read(fd,buf,sizeof(buf));

            if(fd==fd_key)printf("键盘有消息\n");
            else if(fd==fd_mice)printf("鼠标有消息\n");

        }

    }


}
