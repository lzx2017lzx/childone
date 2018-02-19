#include<QApplication>
#include<QWidget>
#include"mywidgets.h"
#include"myapplication.h"
//1、给出用notify函数检测widget窗体事件的案例(提示:创建新的类继承QApplication类，并重载notify函数）
//2、测试函数
//void mousePressEvent(QMouseEvent *ev);
//void mouseDoubleClickEvent(QMouseEvent *ev);
//void keyPressEvent(QKeyEvent *ev);
//void paintEvent(QPaintEvent *ev);
// void mouseReleaseEvent(QMouseEvent *ev);
// void mouseMoveEvent(QMouseEvent *ev);
//void timerEvent(QTimerEvent *ev);
// bool event(QEvent *ev);
int main(int argc,char *argv[])
{
    MyApplication app(argc,argv);

    MyWidgets w;
    w.show();

    w.labelshow();
    return app.exec();
}
