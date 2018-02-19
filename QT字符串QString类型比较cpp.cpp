#include "mywidget.h"
#include<QPushButton>
#include<QDebug>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QString s1("王宝强");
    QString s2("王");
    s1="abcd";
    s2="Abcd";
    if(!QString::compare(s1,s2,Qt::CaseInsensitive))//第三个参数是区分还是不区分大小写的意思，compare比c语言strcmp更智能，完全一致相同返回0，反之返回1
    {
        qDebug()<<"true";
    }
    else
    {
        qDebug()<<"false";
    }
   //QMessageBox::information(this,"标题","Unable to find the user preferences file.\n","The factory default will be used instead");
    //第一个this是mywidget类对象的this指针。

//    QPushButton *button1=new QPushButton("按钮");
//    button1->setParent(this);
//    connect(button1,SIGNAL(clicked()),this,SLOT(ActivateMessagebox()));
//    switch(QMessageBox::warning(this,"标题","could not connect to the <mumble>server.\n","jj","kk","ll",0,-1))
//    {
//        case 0:
//            break;
//        case 1:
//            break;
//    }

}

void MyWidget::ActivateMessagebox()
{
    //QMessageBox::information(this,"22","33");
}
