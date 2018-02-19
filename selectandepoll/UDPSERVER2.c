#include"NETWORK.h"
//本程序模拟接受广播的客户端，这里暂且命令为服务器，注意必须绑定地址0.0.0.0否则就会造成无法接收广播。虽然广播能保证同一网段内的主机能相互连接，但是不保证这个主机中的所有ip地址都会收到广播信息
int main()
{
    int fd=socket(AF_INET,SOCK_DGRAM,0);

    if(fd<0)
    {
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9988);
    addr.sin_addr.s_addr=inet_addr("0.0.0.0");
//    addr.sin_addr.s_addr=inet_addr("192.168.15.137");
    int ret=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    printf("ret=%d\n",ret);
    if(ret<0)return -1;

    char buf[4096];
    memset(buf,0,sizeof(buf));
   // read(fd,buf,sizeof(buf));
    struct sockaddr peer_addr;
    socklen_t addrlen=sizeof(peer_addr);

    recvfrom(fd,buf,sizeof(buf),0,&peer_addr,&addrlen);//其中addrlen即做传入参数又做传出参数

    printf("%s\n",buf);

    strcpy(buf,"你好");    

    sendto(fd,buf,strlen(buf),0,&peer_addr,sizeof(peer_addr));
}
