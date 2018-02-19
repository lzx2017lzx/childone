#include "mywidget.h"
#include<QPushButton>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
   // QMessageBox::information(this,"标题","Unable to find the user preferences file.\n","The factory default will be used instead");
    //第一个this是mywidget类对象的this指针。

    QPushButton *button1=new QPushButton("按钮");
    button1->setParent(this);
    connect(button1,SIGNAL(clicked()),this,SLOT(ActivateMessagebox()));


}

void MyWidget::ActivateMessagebox()
{
    QMessageBox::information(this,"22","33");
}
