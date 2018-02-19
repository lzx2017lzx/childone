#include "Chat.h"

Chat::Chat(QObject *parent) : QObject(parent)
{
    self.ip=getSysIp();
    self.name=getSysName();
#ifdef WIN32
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,1),&wsaData);

#endif
    init();
}

void *Chat::recv_thread(void *ptr)
{
    Chat *This=(Chat*)ptr;

    This->run();
    return NULL;
}

void Chat::run()
{
    while(1)
    {
        struct sockaddr_in addr;
        socklen_t len=sizeof(addr);
        char buf[4096];

        int ret=recvfrom(udp_fd,buf,sizeof(buf),0,(struct sockaddr*)&addr,&len);
        if(ret>0)
        {
            char *ip=inet_ntoa(addr.sin_addr);
            buf[ret]=0;
            qDebug()<<"recv buf is "<<buf<<"ip is"<<ip;
            QJsonDocument doc=QJsonDocument::fromJson(QByteArray(buf));
            //  char ip[16];
            // inet_ntoa(addr.sin_addr);
            handleMsg(doc.object(),ip);
        }else if(ret<0&&errno!=EINTR)
        {
            qDebug()<<"errno recv";
            exit(2);
        }

    }
}

void Chat::init()
{

    this->udp_fd=socket(AF_INET,SOCK_DGRAM,0);
    if(this->udp_fd<=0)
    {
        qDebug()<<"error create socket";
        exit(1);
    }
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9988);
   // addr.sin_addr.s_addr=INADDR_ANY;
    addr.sin_addr.s_addr=inet_addr("192.168.19.27");
    int ret=bind(udp_fd,(struct sockaddr*)&addr,sizeof(addr));
    if(ret!=0)
    {
        qDebug()<<"error bind";
        exit(1);
    }

    int arg=1;
#ifdef WIN32
    setsockopt(udp_fd,SOL_SOCKET,SO_BROADCAST,(char *)&arg,sizeof(arg));
#else
    setsockopt(udp_fd,SOL_SOCKET,SO_BROADCAST,&arg,sizeof(arg));
#endif
    QJsonObject obj;
    obj.insert(CMD,ONLINE);
    obj.insert(NAME,self.name);

    send(obj,BOARDCAST);

    pthread_create(&tid,NULL,recv_thread,this);

}

void Chat::handleMsg(const QJsonObject &obj,QString ip)
{
    QString cmd=obj.value(CMD).toString();
    if(cmd==ONLINE)
    {
        QString name=obj.value(NAME).toString();
        addUser(ip,name);
        //this->others.append(user);
        QJsonObject resp;
        resp.insert(CMD,ONLINEACK);
        resp.insert(NAME,self.name);
        send(resp,ip);
    }
    if(cmd==ONLINEACK)
    {
        QString name=obj.value(NAME).toString();
        addUser(ip,name);
    }
}

void Chat::addUser(QString ip,QString name)
{

    User*user=new User;
    user->ip=ip;
    user->name=name;

    if(others[ip]) delete others[ip];
    others[ip]=user;
    emit sigNewUser(name,ip);
}

QString Chat::getSysIp()
{
    return "";
}

QString Chat::getSysName()
{
    return "姬轩亦";
}

void Chat::send(const QJsonObject &obj,QString ip)
{
    QByteArray buf=QJsonDocument(obj).toJson();

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9988);
    addr.sin_addr.s_addr=inet_addr(ip.toUtf8().data());
    sendto(udp_fd,buf.data(),buf.size(),0,(struct sockaddr*)&addr,sizeof(addr));

}
