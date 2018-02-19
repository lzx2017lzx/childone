#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{

    while(1)
    {
        //建立socket文件
        int cl=socket(AF_INET,SOCK_STREAM,0);

        //建立绑定套接字的地址
        struct sockaddr_in addr;
        addr.sin_family=AF_INET;
        addr.sin_addr.s_addr=inet_addr("127.0.0.1");
        addr.sin_port=htons(23999);
        char cmd[16];
        char user[32];
        char pass[32];
        printf("please input cmd:");
        fgets(cmd,sizeof(cmd),stdin);
        //连接socket文件和套接字
        if(connect(cl,(struct sockaddr*)&addr,sizeof(addr)))
        {
            perror("connect");
            return;
        }
        printf("cmd:%s,strlen cmd:%d",cmd,strlen(cmd));
        if((strcmp(cmd,"r\n")==0)||(strcmp(cmd,"l\n")==0))
        {
            printf("input name:");
            fgets(user,sizeof(user),stdin);

//user[strlen(user)-1]=0;
            printf("input pass:");
            fgets(pass,sizeof(pass),stdin);
  //          pass[strlen(pass)-1]=0;
            char packet[2048]={0};
            sprintf(packet,"%s|%s|%s",cmd,user,pass);
            printf("packet:%s\n",packet);
            int ret=write(cl,packet,strlen(packet));
            printf("ret:%d\n",ret);
            if(ret==0)
            {

                printf("write works well.\n");
            }else if (ret<0)
            {
                printf("write fails. %d\n",errno);
            }

            memset(packet,0,sizeof(packet));
            read(cl,packet,sizeof(packet));
            memset(packet,0,sizeof(packet));
            printf("server resp is %s\n",packet);
        }
            close(cl);
    }
    return 0;
}
