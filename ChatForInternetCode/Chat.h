#ifndef CHAT_H
#define CHAT_H

#include <QObject>
#include<QList>
#ifdef WIN32
#include<winsock2.h>
#define socklen_t int
#else
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#endif
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<pthread.h>
#include<errno.h>
#include<QDebug>
#include<QJsonArray>
#include"chatdef.h"
#include<QMap>
typedef struct
{
    QString name;
    QString ip;
}User;

class Chat : public QObject
{
    Q_OBJECT
public:
    explicit Chat(QObject *parent = 0);

    User self;
    QMap<QString,User*>others;

    int udp_fd;
    pthread_t tid;
   static void *recv_thread(void *ptr);

   void run();
    void init();
    void handleMsg(const QJsonObject& obj,QString ip);
    QString getSysName();
    QString getSysIp();

    void send(const QJsonObject &obj,QString ip);

    void addUser(QString ip,QString name);
signals:
    void sigNewUser(QString name,QString ip);
public slots:
};

#endif // CHAT_H
