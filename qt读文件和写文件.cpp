#include<QCoreApplication>
#include<QFile>
#include<QDataStream>
#include<QDebug>
#include<QBuffer>

/*用QString定义一个字符串，请将其保存到文件text.txt中，并将其信息读出；定义一个结构体含QString 类型定义的变量，int类型定义的变量，将结构体对象数据写入文件test.info中；并将写入的信息读出。
 *用QBuffer，将信息读入到内存，再从内存读出到输出设备(qdebug)
*Qt中读文件最好用QbyteArray类型缓冲区
 * */
struct Student
{
    QString name;
    int age;
    int score;
};

int main(int argc,char *argv[])
{
#if 0
    QString str="中国";
    QFile file("test.txt");
    file.open(QFile::WriteOnly);

   // file.write(str.toLocal8Bit());
    file.write((char *)str.data());//将一个QString类型的变量内的字符串按utf8格式打印到文件。
    file.close();
#endif

#if 0
    {
      Student tom;
      tom.age=18;
      tom.name="tom";
      tom.score=98;

      QFile file("tom.info");
      file.open(QFile::WriteOnly);

      QDataStream ds(&file);
      ds<<tom.age<<tom.name<<tom.score;
      file.close();
    }
#endif

#if 0
    Student s;
    QFile file("tom.info");
    file.open(QFile::ReadOnly);

    QDataStream ds(&file);
    ds>>s.age>>s.name>>s.score;
    file.close();

    qDebug()<<s.age<<s.name<<s.score;
#endif
#if 1
    QBuffer bufFile;
    bufFile.open(QIODevice::WriteOnly);

    bufFile.write("hello");
    bufFile.write("world");

    bufFile.close();

    QByteArray bufData=bufFile.buffer();
    qDebug()<<bufData;

    QByteArray buf(100000,0);
    QByteArray buf2;
    buf2=buf;
#endif
    return 0;
}
