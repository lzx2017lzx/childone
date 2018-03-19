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
    int listen_fd, real_fd;  
    struct sockaddr_in listen_addr, client_addr;  
    socklen_t len = sizeof(struct sockaddr_in);  
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);  
    if(listen_fd == -1)  
    {  
        perror("socket failed   ");  
        return -1;  
    }  
    bzero(&listen_addr,sizeof(listen_addr));  
    listen_addr.sin_family = AF_INET;  
    listen_addr.sin_addr.s_addr =inet_addr("172.18.5.117");  
    listen_addr.sin_port = htons(89);  
    bind(listen_fd,(struct sockaddr *)&listen_addr, len);  
    listen(listen_fd,100);  
    while(1)  
    {  
        real_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &len);  
        if(real_fd == -1)  
        {  
            perror("accpet fail  ");  
            return -1;  
        }  
        if(fork() == 0)  
        {  
            close(listen_fd);  
//            while(1)
//            {
            char pcContent[4096];
            read(real_fd,pcContent,4096);
            printf("pcContent:%s\n",pcContent);
//            }
            exit(0);              
        }  
        close(real_fd);  
    }     


    return 0;
}
