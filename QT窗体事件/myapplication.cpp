#include "myapplication.h"
#include<QDebug>
MyApplication::MyApplication(int argc,char **argv) : QApplication(argc,argv)
{

}


bool MyApplication::notify(QObject *obj,QEvent *ev)
{
    if(this->topLevelWidgets().size()!=0)
    {
        QObject *mainWnd=(QObject *)this->topLevelWidgets()[0];
        if(obj==mainWnd)
        {
            if(ev->type()==QEvent::MouseButtonPress)
            {
                qDebug()<<"notify:mouse press event";
            }
        }
    }
    return QApplication::notify(obj,ev);
}











