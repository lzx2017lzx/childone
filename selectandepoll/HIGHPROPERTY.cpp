#include"NETWORK.h"
#include<list>
using namespace std;

int accept_threads=4;
int worker_threads=8;
pthread_mutex_t mutex;
sem_t sem;
int server;
int epollfd;

class AutoLock
{
    public:
        AutoLock(pthread_mutex_t&mutex):mutex(mutex)
    {
        pthread_mutex_lock(&mutex);
    }
        ~AutoLock()
        {
            pthread_mutex_unlock(&mutex);
        }
        pthread_mutex_t & mutex;
};
#define MyLock(mutex) AutoLock __tmp__lock__(mutex)

class Channel
{
    public:
        char *buf;
        uint32_t packetSize;
        uint32_t readSize;
        int fd;

        Channel(int fd):packetSize(0),readSize(0),fd(fd)
    {
        buf=new char[4096];
    }
        ~Channel()
        {
            printf("socket closede\n");
            close(fd);delete[]buf;
        }
};
list<Channel*>channels;
void epoll_add(int newfd)
{
    Channel*channel=new Channel(newfd);
    struct epoll_event ev;
    ev.data.ptr=channel;
    ev.events=EPOLLIN|EPOLLONESHOT;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,newfd,&ev);
}
void epoll_mod(Channel*channel)
{
    struct epoll_event ev;
    ev.data.ptr=channel;
    ev.events=EPOLLIN|EPOLLONESHOT;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,channel->fd,&ev);

}

void *accept_thread_func(void *ptr)
{
    while(1)
    {
        int newfd=accept(server,NULL,NULL);
        if(newfd>0)
        {
            int flags;
            flags=fcntl(newfd,F_GETFL);
            flags|=O_NONBLOCK;
            fcntl(newfd,F_SETFL,&flags);
            epoll_add(newfd);
        }
    }
    return NULL;
}



Channel *readData(Channel*channel)
{
    int ret;
    if(channel->readSize<4)
    {
        ret=read(channel->fd,channel->buf+channel->readSize,4-channel->readSize);
        if(ret>0)
        {
            channel->readSize+=ret;
            if(channel->readSize==4)
            {
                uint32_t tmp=*(uint32_t*)channel->buf;
                channel->packetSize=ntohl(tmp);
            }
            return readData(channel);
        }
    }
    else
    {
        ret=read(channel->fd,channel->buf+channel->readSize,channel->packetSize+4-channel->readSize);
        if(ret>0)
        {
            channel->readSize+=ret;
            if(channel->readSize==channel->packetSize+4)
                return channel;
            else
                return readData(channel);


        }
    }

    if(ret==0||(ret<0&&errno!=EAGAIN))
    {
        delete channel;
    }else
    {
        epoll_mod(channel);
    }   
    return NULL;

}



void handleData(Channel*channel)
{
    channel->readSize=0;
    channel->buf[channel->readSize]=0;
    printf("%s\n",channel->buf+4);
    epoll_mod(channel);
}

void *worker_thread_func(void *ptr)
{
    while(1)
    {
        sem_wait(&sem);

        Channel*channel=NULL;
        {
            MyLock(mutex);
            if(channels.size()==0)
            {
                break;
            }
            channel=*channels.begin();
            channels.erase(channels.begin());
        }

        if(readData(channel))
        {
            handleData(channel);
        }
    }

    return NULL;
}
void init()
{
    server=myServer(9988,"0.0.0.0");
    epollfd=epoll_create(1024);
    int i=0;
    pthread_t tid;
    for(i=0;i<accept_threads;++i)
    {
        pthread_create(&tid,NULL,accept_thread_func,NULL);
    }

    for(i=0;i<worker_threads;++i)
    {
        pthread_create(&tid,NULL,worker_thread_func,NULL);
    }
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);

    pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex,&attr);
    sem_init(&sem,0,0);
    return;
}

void exec()
{
    struct epoll_event evs[8];
    while(1)
    {
        int ret=epoll_wait(epollfd,evs,8,5000);
        printf("exec ret=%d\n",ret);
        if(ret>0)
        {
            int i;
            for(i=0;i<ret;i++)
            {
                Channel *channel=(Channel*)evs[i].data.ptr;
                {
                    MyLock(mutex);
                    channels.push_back(channel);
                }

                sem_post(&sem);
            }
        }
        else if(ret<0&&errno!=EINTR)
        {
            printf("errno\n");
            break;
        }
    }

}

int main()
{
    init();
    exec();
    return 0;
}
