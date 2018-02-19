#include "widget.h"
#include<QTimer>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
   timerid1=startTimer(100);
   timerid2=startTimer(200);
   timerid3=startTimer(300);


}

Widget::~Widget()
{

}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==timerid1)
    {
        qDebug()<<"1";
    }else if(event->timerId()==timerid2)
    {
        qDebug()<<"2";
    }else if(event->timerId()==timerid3)
    {
        qDebug()<<"3";
    }
}
