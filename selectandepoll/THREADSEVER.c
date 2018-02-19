#include"NETWORK.h"

void *thread_func(void *ptr)
{
   // int newfd=(intptr_t)ptr;
    int newfd=*(int*)ptr;
    char buf[1024];
    read(newfd,buf,sizeof(buf));

    printf("%s\n",buf);

}
//多线程服务器
int main()
{
    int server=myServer(9988,"0.0.0.0");

    while(1)
    {
        int newfd=myAccept(server,NULL,NULL);
        
        pthread_t tid;
    
        //pthread_create(&tid,NULL,thread_func,(void *)(intptr_t)newfd);        
        pthread_create(&tid,NULL,thread_func,&newfd);        
        pthread_detach(tid);

    }
}











