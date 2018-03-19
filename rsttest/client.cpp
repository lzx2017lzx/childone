#include <iostream>
#include<string>
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

using namespace std;

int main(int argc, char *argv[])
{
    int send_sk;  
    struct sockaddr_in s_addr;  
    socklen_t len = sizeof(s_addr);  
    send_sk = socket(AF_INET, SOCK_STREAM, 0);  
    if(send_sk == -1)  
    {  
        perror("socket failed  ");  
        return -1;  
    }  
    bzero(&s_addr, sizeof(s_addr));  
    s_addr.sin_family = AF_INET;  

    inet_pton(AF_INET,"172.18.5.117",&s_addr.sin_addr);  
    s_addr.sin_port = htons(89);  
    if(connect(send_sk,(struct sockaddr*)&s_addr,len) == -1)  
    {  
        perror("connect fail  ");  
        return -1;  
    }  
    while(1)
    {
        char pcContent[5000]={"helloworld"};
        int ret=write(send_sk,pcContent,5000);
        cout<<"ret:"<<ret<<endl;
        cout<<"errno:"<<errno<<endl;
        if(errno==104)
        {
            continue;
        }
    }
    while(1)
    {
        sleep(1);
    }

    close(send_sk);

    return 0;
}
