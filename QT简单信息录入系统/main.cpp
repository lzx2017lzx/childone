#include<QApplication>
#include<mywidget.h>

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    MyWidget w1;
    w1.show();

    w1.readstream();
    return app.exec();
}
