#ifndef REDIS_H
#define REDIS_H

#include<hiredis/hiredis.h>
#include<QString>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
class Redis
{
public:
    Redis();
    ~Redis();


   int addSet(QString set,QString value);
   QStringList getSet(QString set);

   QString getHashMember(QString name,QString keyname);
   int addHash(QString name,QStringList keys,QStringList values,int timeout=1000000);
   void updateExpire(QString name,int timeout=10000000);

   //redisContext* connect(const char *ip,unsigned short port);
#if 0
   int addHash(QString name,QJsonObject obj);
   int addHash(QString name,...);
#endif
private:
   redisContext*ctx;
};

#endif // REDIS_H
