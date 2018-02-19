#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    pushbutton.setParent(this);
    pushbutton.setFixedHeight(50);
    pushbutton.setFixedWidth(300);
    pushbutton.installEventFilter(this);
    this->installEventFilter(this);
  //  pushbutton.setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//void Widget::event(QEvent *event)
//{
//    switch(event->type())
//    {
//    case QEvent::Close:
//        qDebug()<<"close:";
//        break;
//    case QEvent::MouseMove:
//        qDebug()<<"mouse move";
//        break;
//   // case QEvent::QPush


//    }
//}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==&pushbutton)
    {

        QMouseEvent *env=static_cast<QMouseEvent*>(event);
     if(event->type()==QEvent::MouseMove)
     {
         pushbutton.setText(QString("button Mouse move:(%1,%2)").arg(env->x()).arg(env->y()));
        return true;
     }

     if(event->type()==QEvent::MouseButtonPress)
     {
         pushbutton.setText(QString("button Mouse press:(%1,%2)").arg(env->x()).arg(env->y()));
        return true;
     }

     if(event->type()==QEvent::MouseButtonRelease)
     {
         pushbutton.setText(QString("button MouseButtonRelease:(%1,%2)").arg(env->x()).arg(env->y()));
        return true;
     }
    }
    else if(watched==this)
    {
        qDebug()<<".....";
        QMouseEvent *env=static_cast<QMouseEvent*>(event);
        if(event->type()==QEvent::MouseMove)
        {
            pushbutton.setText(QString("Mouse move:(%1,%2)").arg(env->x()).arg(env->y()));
           return true;
        }

        if(event->type()==QEvent::MouseButtonPress)
        {
            pushbutton.setText(QString("Mouse press:(%1,%2)").arg(env->x()).arg(env->y()));
           return true;
        }

        if(event->type()==QEvent::MouseButtonRelease)
        {
            pushbutton.setText(QString("MouseButtonRelease:(%1,%2)").arg(env->x()).arg(env->y()));
           return true;
        }

    }

        return QWidget::eventFilter(watched,event);



}
