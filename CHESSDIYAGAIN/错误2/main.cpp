#include<QApplication>
#include"mainwindow.h"
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    MainWindow m1;
    m1.show();


    return app.exec();
}
