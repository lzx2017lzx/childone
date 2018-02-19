#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/epoll.h>
#include<list>
#include<map>
#include<arpa/inet.h>
#include<pthread.h>
#include<unistd.h>
#include<iostream>
#include"WRITEREADAVOIDPASTE.h"
using namespace std;






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
            return 0;
        }
        perror("connect:");
        char temp[4028]="hello";
        
        mywritebuf(cl,temp);
        memcpy(temp,"world",5);
        mywritebuf(cl,temp);
        

        close(cl);
    }
    return 0;
}
