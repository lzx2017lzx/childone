#include<QApplication>
#include<QMessageBox>
#include"mywidget.h"
int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    MyWidget w1;
    w1.show();

   // QPushButton pushButton(&w1);

   // QMessageBox::information(&pushButton,"标题","Unable to find the user preferences file.\n","The factory default will be used instead");




    return app.exec();
}
