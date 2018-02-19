#include<QApplication>
#include<QWidget>
#include"mywidget.h"
//编写程序拖动鼠标可以移动窗口
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    MyWidget w;
    w.show();

    return app.exec();
}

