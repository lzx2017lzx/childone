#include "myclass2.h"
#include<QDebug>
MyClass2::MyClass2(QObject *parent) : QObject(parent)
{

}

void MyClass2::CalledByOther()
{
    qDebug()<<"this func is called";
}

void MyClass2::slotFunc()
{
    this->CalledByOther();
}
