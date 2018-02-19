#include"NETWORK.h"
#include<list>
using namespace std;
#include<pthread.h>
list<int>socks;
#include<map>
pthread_mutex_t mutex;
pthread_cond_t cond;

int epollfd;
struct Channel
{
    int fd;
    char *buf;
    int readSize;
    int packetSize;
    Channel(int fd)
    {
        buf=new char[4096];
        readSize=0;
        packetSize=0;
        this->fd=fd;
    }
    ~Channel()
    {
        delete buf;
        close(fd);
    }
};

map<int,Channel*>channels;



void handleData(Channel*channel)
{
    int newfd=channel->fd;
    char *buf=channel->buf+4;
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
    delete channel;
}

void recvData(Channel*channel)
{
    int ret=read(channel->fd,channel->buf+channel->readSize,channel->packetSize-channel->readSize+4);
    if(ret>0)
    {
        channel->readSize+=ret;
        if(channel->readSize==channel->packetSize+4)
        {
            handleData(channel);   
        }

    }else if((ret<0&&errno!=EAGAIN)||ret==0)
    {
        pthread_mutex_lock(&mutex);
        channels.erase(channels.find(channel->fd));
        pthread_mutex_unlock(&mutex);

        delete channel;
    }else
    {
        struct epoll_event ev;
        ev.data.fd=channel->fd;
        ev.events=EPOLLIN|EPOLLONESHOT;
        epoll_ctl(epollfd,EPOLL_CTL_MOD,channel->fd,&ev);

    }

}
void handle(int newfd)
{
    pthread_mutex_lock(&mutex);
    Channel *channel=channels[newfd];
    pthread_mutex_unlock(&mutex);

    if(channel->readSize<4)
    {
        int ret=read(channel->fd,channel->buf+channel->readSize,4-channel->readSize);
        if(ret>0)
        {
            channel->readSize+=ret;
            if(channel->readSize==4)
            {
                uint32_t *p=(uint32_t *)channel->buf;
                channel->packetSize=ntohl(*p);//是不是buf里存储的是整形存储空间的首地址
            recvData(channel);

            }
        }
        else if(ret<0&&errno!=EAGAIN||ret==0)
        {
            pthread_mutex_lock(&mutex);
            channels.erase(channels.find(newfd));
            pthread_mutex_unlock(&mutex);

            delete channel;
        }
        else
        {
            struct epoll_event ev;
            ev.data.fd=newfd;
            ev.events=EPOLLIN|EPOLLONESHOT;
            epoll_ctl(epollfd,EPOLL_CTL_MOD,newfd,&ev);

        }


    }
    else
    {
        recvData(channel);

    }
}
void *thread_func(void *ptr)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond,&mutex);
        pthread_mutex_unlock(&mutex);
        while(1)
        {


            pthread_mutex_lock(&mutex);
            if(socks.size()==0)
            {
                pthread_mutex_unlock(&mutex);
                break;
            }
            int newfd=*socks.begin();
            socks.erase(socks.begin());

            pthread_mutex_unlock(&mutex);
            handle(newfd);
#if 0
            struct epoll_event ev;
            ev.data.fd=newfd;
            ev.events=EPOLLIN|EPOLLONESHOT;
            epll_ctl(epollfd,EPOLL_CTL_MOD,newfd,&ev);
#endif
        }
    }

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
    int server=myServer(9977,"0.0.0.0");

    close(open("user.data",O_CREAT|O_EXCL,0777));

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_t tid;
    pthread_create(&tid,NULL,thread_func,NULL);

    epollfd=epoll_create(1024);
    epoll_add(epollfd,server,EPOLLIN);

    struct epoll_event ev[8];
    while(1)
    {
        int ret=epoll_wait(epollfd,ev,8,5000);
        if(ret>0)
        {
            for(int i=0;i<ret;i++)
            {
                if(ev[i].data.fd==server)
                {
                    int newfd=myAccept(server,NULL,NULL);
                    epoll_add(epollfd,newfd,EPOLLIN|EPOLLONESHOT);
                    Channel *channel=new Channel(newfd);
                    channels[newfd]=channel;
                    int flags=fcntl(newfd,F_GETFL);
                    flags|=O_NONBLOCK;
                    fcntl(newfd,F_SETFL,&flags);
                }
                else
                {
                    pthread_mutex_lock(&mutex);
                    socks.push_back(ev[i].data.fd);
                    pthread_mutex_unlock(&mutex);
                    pthread_cond_signal(&cond);

                    // epoll_ctl(epollfd,EPOLL_CTL_DEL,ev[i].data.fd,NULL);



                }
            }

        }

    }

#if 0
    while(1)
    {
        int newfd=accept(server,NULL,NULL);
        if(newfd>0)
        {
            pthread_mutex_lock(&mutex);
            socks.push_back(newfd);
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&cond);
        }
    }
#endif
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


