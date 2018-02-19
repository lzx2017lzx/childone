#include"NETWORK.h"

void handle(int newfd)
{
    printf("inhandle\n");
        char *buf= myReadBuf(newfd);
        char *saveptr;
        const char *type=strtok_r(buf,"|",&saveptr);
        if(type==NULL)
        {
            return;
        }
        const char *user=strtok_r(NULL,"|",&saveptr);
        if(user==NULL)
        {
            return;
        }
        const char*pass=strtok_r(NULL,"|",&saveptr);
        if(user==NULL)
        {
            return;
        }

        if(type[0]=='r')
        {

    printf("reginst\n");
            FILE *fp=fopen("user.data","a+");
            fprintf(fp,"%s\n%s\n",user,pass);
            fclose(fp);

            myWriteBuf(newfd,"r|ok");    
        }
        else if(type[0]=='l')
        {
            char ubuf[1024];
            char pbuf[1024];
            char *p;
            FILE *fp=fopen("user.data","r");
            while(1)
            {
                p=fgets(ubuf,sizeof(ubuf),fp);
                if(p==NULL)break;
                fgets(pbuf,sizeof(pbuf),fp);
                ubuf[strlen(ubuf)-1]=0;
                pbuf[strlen(pbuf)-1]=0;
                if(strcmp(ubuf,user)==0&&strcmp(pbuf,pass)==0)
                {
                    myWriteBuf(newfd,"l|ok");
                    break;

                }
            }

            if(p==NULL)
            {
                myWriteBuf(newfd,"l|err");
            }
            fclose(fp);

        }
        else
        {
            myWriteBuf(newfd,"unknown command");
        }
        free(buf); 
        close(newfd);

}

void epoll_add(int epollfd,int sock,int event)
{
    struct epoll_event ev;
    ev.data.fd=sock;
    ev.events=event;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,sock,&ev);
}


int main()
{
    int server=myServer(9989,"0.0.0.0");

    close(open("user.data",O_CREAT|O_EXCL,0777));
    int epollfd=epoll_create(1024);

    epoll_add(epollfd,server,EPOLLIN);

    struct epoll_event ev[8];
    while(1)
    {
        int ret=epoll_wait(epollfd,ev,sizeof(ev)/sizeof(*ev),5000);
        if(ret>0)
        {
            int i;
            for(i=0;i<ret;i++)
            {
                if(ev[i].data.fd==server)
                {
                    int newfd=myAccept(server,NULL,NULL);
                    epoll_add(epollfd,newfd,EPOLLIN);
                }
                else
                {
                    handle(ev[i].data.fd);
                }
            }

        }
        else if(ret==0)
        {
            
        }
        else if(ret<0&&errno==EINTR)
        {

        }else
        {
            printf("errno=%d\n",errno);
            break;
        }
    }
#if 0
    while(1)
    {
        int newfd=myAccept(server,NULL,NULL);
        if(newfd==-1)
        {
            break;
        }


















    } 
    return 0;
#endif
}


