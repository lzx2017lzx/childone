#include "widget.h"
#include<QSizePolicy>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

   // this->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
    QPalette palette; 
     QPixmap pixmap;
    pixmap.load(":/new/prefix1/8.jpg");
    this->setAutoFillBackground(true);
   palette.setBrush(QPalette::Window,QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
   this->setPalette(palette);
}

Widget::~Widget()
{

}
