#include"NETWORK.h"
fd_set saveSet;
int maxfd;
void handle(int newfd)
{
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
    FD_CLR(newfd,&saveSet);
    if(maxfd==newfd)maxfd--;
}
int main()
{
    int server=myServer(9989,"0.0.0.0");


    maxfd=server;
    FD_ZERO(&saveSet);
    FD_SET(server,&saveSet);
    close(open("user.data",O_CREAT|O_EXCL,0777));

    while(1)
    {
        fd_set set;
        struct timeval tv;
        memcpy(&set,&saveSet,sizeof(set));
        tv.tv_sec=5;
        tv.tv_usec=0;
        int ret=select(maxfd+1,&set,NULL,NULL,&tv);
        if(ret>0)
        {
            if(FD_ISSET(server,&set))
            {
                int newfd=myAccept(server,NULL,NULL);
                if(maxfd<newfd)maxfd=newfd;
                FD_SET(newfd,&saveSet);
            }

            int i;
            for(i=server+1;i<maxfd+1;++i)
            {
                if(FD_ISSET(i,&set))
                {
                    handle(i);
                }
            }
        }
        else if(ret==0)
        {
            
        }
        else if(ret<0&&errno==EINTR)
        {
            
        }
        else
        {
            printf("errno,errno=%d\n",errno);
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
            close(newfd);


















        } 
        return 0;
#endif
    }


