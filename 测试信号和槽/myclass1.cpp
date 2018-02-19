#include "myclass1.h"
#include<QDebug>
MyClass1::MyClass1(QObject *parent) : QObject(parent)
{

}

void MyClass1::CalledByOther()
{
   // qDebug()<<"this func is called";
    emit this->sigFunc();
}

//void MyClass1::sigFunc()
//{
//    qDebug()<<"mmmm";
//}
