#include<QApplication>
#include"mywidget.h"
#include<QCoreApplication>
//1、在一个能正常运行的删除QApplication app第一句，理解含义；
//2、删除return app。exec()，改用return 0；理解最后一句的用途。
int main(int arg,char *argv[])
{
    QApplication app(arg,argv);
   // QCoreApplication app(arg,argv);
    MyWidget w;
    w.show();

    return app.exec();
    //return 0;
}
