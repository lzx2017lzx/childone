#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>

fd_set saveSet;//saveSet用来存储所有的文件描述符，方便初始化set集合，本代码中采用memcpy的方式
int maxfd;

void handleset(int newfd)
{
    char buf[1024]={0};
    int ret=read(newfd,buf,sizeof(buf));
    char *saveptr;
    const char * type=strtok_r(buf,"|",&saveptr);
    const char * user=strtok_r(NULL,"|",&saveptr);
    const char * pass=strtok_r(NULL,"|",&saveptr);

    if(type[0]=='r')
    {
        FILE *fp=fopen("user.data","a+");
        fprintf(fp,"%s%s",user,pass);
        fclose(fp);

        printf("regist is ok.\n");
        write(newfd,"r|ok",4);
    }else if(type[0]=='l')
    {
        char ubuf[1024];
        char pbuf[1024];
        char *p;

        FILE *fp=fopen("user.data","r");
        while(1)
        {
            p=fgets(ubuf,sizeof(ubuf),fp);
            if(p==NULL)
                break;
            fgets(pbuf,sizeof(pbuf),fp);
            ubuf[strlen(ubuf)-1]=0;
            pbuf[strlen(pbuf)-1]=0;

            if(strcmp(ubuf,user)==0&&strcmp(pbuf,pass)==0)
            {
                write(newfd,"l|ok",4);
                break;
            }

        }

        if(p==NULL)
        {
            write(newfd,"l|err",5);
        }

        fclose(fp);
    }
    else
    {
        char temp[1024]="unknown command";
        write(newfd,temp,strlen(temp));
    }

    // free(buf);
    close(newfd);
    //清理集合
    FD_CLR(newfd,&saveSet);
    if(maxfd==newfd)maxfd--;

}

int main()
{
    //创建套接字
    int fd=socket(AF_INET,SOCK_STREAM,0);
    int maxfd;
    FD_ZERO(&saveSet);
    FD_SET(fd,&saveSet);//serveer in saveSet
    //    maxfd=fd;

    close(open("user.data",O_CREAT|O_EXCL,0777));

    //设置结诟体，用来绑定IP和端口
    struct sockaddr_in addr;
    addr.sin_addr.s_addr=inet_addr("0.0.0.0");
    addr.sin_family=AF_INET;
    addr.sin_port=htons(23999);    

    //绑定地址端口/信息到socket文件
    bind(fd,(struct sockaddr*)&addr,sizeof(addr));

    //监听
    listen(fd,10);//同时监听10个客户端
    //读客户端的文件信息
    char buf[1024];
    memset(buf,0,sizeof(buf));
    
    printf("befroe while\n");
    while(1)
    {
        printf("in while\n");
        fd_set set;//创建文件描述符集合

        struct timeval tv;//设定监听阻塞时间
        //初始化maxfd、set、tv
        memcpy(&set,&saveSet,sizeof(set));

        tv.tv_sec=10;
        tv.tv_usec=0;
        int ret=select(maxfd+1,&set,NULL,NULL,&tv);
        printf("select ret:%d\n",ret);
        if(ret>0)
        {
            if(FD_ISSET(fd,&set))
            {
                printf("before accept\n");
                int newfd=accept(fd,NULL,NULL);//创建服务器和客户端之间通信的文件
                printf("accept works.\n");
                if(maxfd<newfd)
                {
                    maxfd=newfd;
                }
                if(newfd<0)
                {
                    printf("communication fails.\n");
                    return;
                }
                FD_SET(newfd,&saveSet);//server,newfd都在saveSet

                int i;
                for(i=fd+1;i<maxfd+1;++i)
                {
                    if(FD_ISSET(i,&set))
                    {
                        printf("this is going to handleset.\n");
                        handleset(i);

                    }


                }
            }else if(ret==0)
            {
                //没有socket有消息

            }else if(ret<0&&errno==EINTR)
            {
                //被中断打断
            }else
            {
                //严重错误
                printf("error,errno=%d\n",errno);
                break;
            }
        }
    }

#if 0
#endif  
    return 0;

}
