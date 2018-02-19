#include "redis.h"
#include<QStringList>
#include<QDebug>
Redis::Redis()
{
    ctx=redisConnect("127.0.0.1",6379);
	qDebug()<<"ctx:"<<ctx;
}

Redis::~Redis()
{
    redisFree(ctx);
}



int Redis::addSet(QString set, QString value)
{
    QString cmd=QString("sadd %1 %2").arg(set,value);

    redisReply*ret=(redisReply*)redisCommand(ctx,cmd.toUtf8().data());
	qDebug()<<cmd;

    if(ret==NULL)
    {
        return -1;
    }

    qDebug()<<"reply type is"<<ret->type;
   qDebug()<<"reply str is："<<ret->str;
   qDebug()<<"reply int is:"<<ret->integer;

//    if(ret->type==REDIS_REPLY_STATUS)
//    {
//        if(QString(ret->str).toLower()=="ok")
//        {
//            freeReplyObject(ret);
//            return 0;
//        }
//    }


    freeReplyObject(ret);
    return 0;
}

QStringList Redis::getSet(QString set)
{
    QStringList retList;
    redisReply*ret=(redisReply*)redisCommand(
                ctx,"smembers %s",set.toUtf8().data()

                );

    if(ret==NULL)
    {
        qDebug()<<"getSet ret is null";
        return retList;
    }
    qDebug()<<"getset return"<<ret->type;
    if(ret->type==REDIS_REPLY_ARRAY)
    {
        for(int i=0;i<ret->elements;++i)
        {
            redisReply*r=ret->element[i];
            retList.append(r->str);
        }
    }

    return retList;
}

QString Redis::getHashMember(QString name, QString keyname)
{
    QString retStr;
    redisReply*ret=(redisReply*)redisCommand(ctx,
                   "hget %s %s",name.toUtf8().data(),
                    keyname.toUtf8().data());

    if(ret->type==REDIS_REPLY_INTEGER)
        retStr=QString::number(ret->integer);
    else
        retStr=ret->str;

    if(ret)
        freeReplyObject(ret);

    return retStr;
}


#if 0
int Redis::addHash(QString name, QJsonObject obj)
{
    QStringList keys=obj.keys();
    foreach(QString key,keys)
    {
        QString value=obj[key].toString();
        QString cmd=QString("hset %1 %2 %3").arg(name,key,value);
        redisCommand(ctx,cmd.toUtf8().data());




    }
    return 0;
}
#endif
int Redis::addHash(QString name, QStringList keys,QStringList values, int timeout)
{
    int count=keys.size();
    if(values.size()<count)
        return -1;

    for(int i=0;i<count;++i)
    {
        QString key=keys[i];
        QString value=values[i];

        redisReply*ret=(redisReply*)redisCommand(ctx,
                       "hset %s %s %s",name.toUtf8().data(),
                        key.toUtf8().data(),value.toUtf8().data());
	qDebug()<<"addHash works"<<endl;
	qDebug()<<"key:"<<key<<endl;
	qDebug()<<"value:"<<value<<endl;
	qDebug()<<"ret->interger:"<<ret->integer;	
	qDebug()<<"ret:"<<ret->type<<"ret:len"<<ret->len;
	printf("ret str:%s\n",ret->str);
        if(ret)
        freeReplyObject(ret);
    }

    updateExpire(name,timeout);


    return 0;
}

void Redis::updateExpire(QString name, int timeout)
{
    redisReply*ret=(redisReply*)redisCommand(ctx,
                   "expire %s %d",name.toUtf8().data(),
                    timeout);

    if(ret)
        freeReplyObject(ret);
}



#if 0
int Redis::addHash(QString name,...)
{
    va_list ap;
    va_start(ap,name);
    while(1)
    {
        const char* key=va_arg(ap,const char*);
        if(key==NULL)
            break;
        const char *value=va_arg(ap,const char*);
        redisReply*ret=(redisReply*)redisCommand(ctx,"hset %s %s %s",name.toUtf8().data(),key,value);

        if(ret)
        freeReplyObject(ret);
    }
    va_end(ap);

    return 0;
}
#endif
//redisContext *Redis::connect(const char *ip, unsigned short port)
//{

//}
