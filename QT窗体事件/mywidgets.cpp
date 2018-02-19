#include "mywidgets.h"
#include<QDebug>
#include<QMouseEvent>
#include<QPainter>
MyWidgets::MyWidgets(QWidget *parent) : QWidget(parent)
{
//    t1=startTimer(1000);
//    t2=startTimer(5000);
}

void MyWidgets::mousePressEvent(QMouseEvent *ev)
{
#if 0
    QPoint pt=ev->pos();
    qDebug()<<pt;

    Qt::MouseButton b=ev->button();
    if(b==Qt::LeftButton)
    {
        qDebug()<<"left button is down";
    }
    else if(b==Qt::RightButton)
    {
        qDebug()<<"right button is down";
    }

    Qt::KeyboardModifiers m=ev->modifiers();
    if(m==Qt::ShiftModifier)
    {
        qDebug()<<"shift is down";
    }
#endif
   // label=new QLabel("你好");
   // label->setParent(this);
   // label->show();//如果本程序没有添加，程序运行后点击产生鼠标事件，是不会有label的。因为w1show时候没有带上label标签
    qDebug()<<"鼠标单击";
}

void MyWidgets::labelshow()
{
//    label1=new QLabel("你好");
//    label1->setParent(this);

//    label1->show();

   // QLabel label("他好");
  //  label.show();
     //label.exec();
}

void MyWidgets::mouseDoubleClickEvent(QMouseEvent *ev)
{
   // qDebug()<<"鼠标双击";
}

void MyWidgets::keyPressEvent(QKeyEvent *ev)
{
//    qDebug()<<"key event";

//    int v='J';
//    qDebug()<<"J is"<<v;

//    qDebug()<<ev->key();
//    qDebug()<<ev->modifiers();
//    qDebug()<<ev->isAutoRepeat();
}

void MyWidgets::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawLine(QPoint(0,0),QPoint(100,100));
}

void MyWidgets::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<"释放鼠标";
}

void MyWidgets::mouseMoveEvent(QMouseEvent *ev)
{

}

void MyWidgets::timerEvent(QTimerEvent *ev)
{
//    if(ev->timerId()==t1)
//    {
//        qDebug()<<"one second timeout";
//    }
//    else if(ev->timerId()==t2)
//    {
//        qDebug()<<"five second timeout";
//        killTimer(t2);
//    }
}

bool MyWidgets::event(QEvent *ev)
{
//    if(ev->type()==QEvent::Enter)
//    {
//           qDebug()<<"mouse enter in event";
//    }else if(ev->type()==QEvent::Show)
//    {
//            qDebug()<<"widget shows";
//    }

    return QWidget::event(ev);
}






