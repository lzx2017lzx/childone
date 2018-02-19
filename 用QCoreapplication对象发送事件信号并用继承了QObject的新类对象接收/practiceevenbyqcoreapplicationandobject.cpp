#include<QCoreApplication>
#include"myobject.h"
/*创建新的类继承于qobject；并编写出event函数（是QObject类中的虚函数)；在主函数中用sendEvent函数(是QCoreApplication中的公有函数),调用qobject中的event函数。
 *
 *
 * */
int main(int argc,char *argv[])
{
    QCoreApplication app(argc,argv);
    QObject *obj=new MyObject;
    app.sendEvent(obj,new QEvent(QEvent::User));

    return app.exec();


}
