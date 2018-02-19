#include "mybutton.h"
#include<QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::mousePressEvent(QMouseEvent *event)
{

    if(event->button()==Qt::RightButton)
    {
        qDebug()<<"right";
        close();
    }else if(event->button()==Qt::LeftButton)
    {
        qDebug()<<"left";
        p=event->globalPos()-this->frameGeometry().topLeft();
        //event->Drop();
        event->ignore();
    }
}
//void QAbstract3DInputHandler::mouseMoveEvent(QMouseEvent *event, const QPoint &mousePos)

void MyButton::mouseMoveEvent(QMouseEvent *event)
//void Widget::mouseMoveEvent(QMouseEvent *event,const QPoint &mousePos)//错误用法
{
#if 1
    if(event->buttons()&Qt::LeftButton)
    {
        //qDebug()<<"mousePos:"<<mousePos.x()<<mousePos.y();
        qDebug()<<"p:"<<p.x()<<p.y();
        move(event->globalPos()-p);
        qDebug()<<"event->globalPos()-p";
    }
#endif
#if 0
   // 错误用法
    if(event->buttons()==Qt::LeftButton)
    {
        qDebug()<<"mouseMoveEvent works";
        move(event->globalPos()-p);
    }
#endif

}
