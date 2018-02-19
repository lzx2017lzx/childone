#include "myobject.h"
#include<QDebug>
MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

bool MyObject::event(QEvent *event)
{
    if(event->type()==QEvent::User)
    {
        qDebug()<<"event recived;";
        return true;
    }
    return false;
}


