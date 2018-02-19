#include<QApplication>
#include<QWidget>

#include<QDebug>
#include"myclass1.h"
#include"myclass2.h"
/*
定义两个类继承object，在测试信号和槽？

*/
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    #if 0
    QObject *obj1=new QObject;
    QObject *obj2=new QObject;

    obj2->setParent(obj1);

    delete obj1;

    #endif

#if 0
    QWidget *w1=new QWidget;
    QWidget *w2=new QWidget;
    w1->setParent(w2);
    delete w2;
#endif
    MyClass1 c1;
    MyClass2 c2;

    QObject::connect(&c1,SIGNAL(sigFunc()),&c2,SLOT(slotFunc()));
    c1.CalledByOther();
//    qDebug()<<"hello world";
//    qDebug("hello world! %d\n",10);

//    qWarning()<<"This is warnings";
//    qWarning("aaa");

//    qCritical()<<"this is critical";

//    QWidget win;
//    win.show();

    return app.exec();
}
