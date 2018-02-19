#include<QCoreApplication>
#include<QString>
#include<QByteArray>
#include<QDebug>

/*①比较QString、QByteArray类型变量的size大小；②、将QByteArray类型变量按字符串形式打印输出；③、练习str+=“  ”的效果
 * ④输出str.indexof("一个")的效果；⑤、使用str.split("一")功能；⑥、buf.toStdString().data()用字符串的方式打印字符数组对象内的字符。
 * char *data=buf.data()使用QByteArray定义的buf对象，取出对象内存储的字符序列的首地址,str.trimmed()消除字符串首尾空\t\n\r的功能
 *str.stratsWith("mn")的功能，练习qint32定义变量,练习str.toInt()、str.sprintf("%d",a)、QString("say%2valueis%1").arg(1000).arg("helloqorld");
 *
 * */
int main(int argc,char *arg[])
{
    QCoreApplication app(argc,arg);
#if 0
 QString str="王宝强";
 QByteArray ba="王宝强";
 qDebug()<<"string size"<<str.size()<<str;
 qDebug()<<"byte array size"<<ba.size()<<ba;
 ba.toStdString();
qDebug()<<ba.toStdString().data();//怎样将一个字符数组转换成字符串

 str+="它是一只坏猫，一只，一只";
qDebug()<<str.indexOf("一个");
QList<QString>substrs=str.split("一");
qDebug()<<substrs;

str="1288898989898989898989898989898989";//练习str.toInt()、str.sprintf("%d",a)、QString("say%2valueis%1").arg(1000).arg("helloqorld");
qDebug()<<str.toInt();
str="sm";
QString st1("abcd");
qint32 a=89;//练习qint32定义变量
//str.sprintf("%d%s%s",a,st1.data());

str=QString("say%2 value is %1").arg(1000).arg("hello world");


qDebug()<<str;
str="mnab";
if(str.startsWith("mn"))//str.stratsWith("mn")的功能
{
    qDebug()<<"yes";
}

str=" \t  \n abc de  \t \n ";
qDebug()<<"trimmed"<<str.trimmed();//str.trimmed()消除字符串首尾空\t\n\r的功能
qDebug()<<str;
#endif

#if 1
QByteArray ba;
ba="中文";

QByteArray buf(1024,0);

//qDebug()<<buf.size();
buf+="abc";

char *data=buf.data();//char *data=buf.data()使用QByteArray定义的buf对象，取出对象内存储的字符序列的首地址
qDebug()<<buf.size();
strcpy(data,"helloworld");
qDebug()<<buf.size();
qDebug()<<buf.toStdString().data();//buf.toStdString().data()用字符串的方式打印字符数组对象内的字符。

#endif

    return 0;
}
