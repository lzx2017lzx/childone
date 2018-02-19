#include "mywidget.h"
#include<QDebug>
#include<QMouseEvent>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    this->posMouseOrigin=QCursor::pos();
    qDebug()<<"posMouseOriginPress :"<<this->posMouseOrigin;
}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
//    QPoint ptMouseNow=QCursor::pos();
//    QPoint ptDelta=ptMouseNow-this->posMouseOrigin;

//    move(this->pos()+ptDelta);

//    posMouseOrigin=ptMouseNow;
    qDebug()<<"posmouseoriginmove:"<<this->posMouseOrigin;
}

void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{

}

