#include<QCoreApplication>
#include<QDebug>
//枚举的使用方式
 enum a{red,colum,age};
int main(int argc,char *argv[])
{
    QCoreApplication app(argc,argv);

    a c;
    c=age;
    qDebug()<<c;


    app.exec();
}
