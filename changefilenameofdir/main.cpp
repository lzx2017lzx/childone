#include<QCoreApplication>

#include <QDir>
#include <iostream>
#include<QFile>
#include<QDebug>

//1、将视频加密另存为新视频
//2、将加密的视频解密
//encode
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QDir dir;
    //dir.setPath("F:\\清理\\视频\\video");
    //dir.setPath("F:\\清理\\视频\\视频");
    dir.setPath("F:\\清理\\视频\\newvideo");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();
    std::cout << "     Bytes Filename" << std::endl;
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        QString s1=fileInfo.fileName();
        if(s1.endsWith(".mp4"))//判断字符串是不是以.mp4结尾
        {
//            QFile file1("F:\\清理\\视频\\video\\"+s1);
//            QFile file2("F:\\清理\\视频\\video\\"+QString::number(i)+".mp4");
            QFile file1("F:\\清理\\视频\\newvideo\\"+s1);
            QFile file2("F:\\清理\\视频\\newvideo\\"+QString::number(i)+"nw.mp4");
            if(!file1.open(QIODevice::ReadOnly))
            {
                qDebug()<<"error open file1";
            };

            if(!file2.open(QIODevice::WriteOnly))
            {
                qDebug()<<"error open file2";
            }

            while(!file1.atEnd())
            {
                QByteArray m=file1.read(1024);
                m.append("1");

                file2.write(m);
                qDebug()<<"i";
            }
            file1.close();
            file2.close();
            //  if((fileInfo.size()!=0)&&)
            std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10).arg(fileInfo.fileName()));
            std::cout << std::endl;
        }
    }
    return 0;
}

//decode
int main01(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QDir dir;
   // dir.setPath("F:\\清理\\视频\\video");
 dir.setPath("F:\\清理\\视频\\encvideo");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();
    std::cout << "     Bytes Filename" << std::endl;
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        QString s1=fileInfo.fileName();
        if(s1.endsWith(".mp4"))//判断字符串是不是以.mp4结尾
        {
           // QFile file1("F:\\清理\\视频\\video\\"+s1);
           // QFile file2("F:\\清理\\视频\\video\\"+QString::number(i)+"dec.mp4");
            QFile file1("F:\\清理\\视频\\encvideo\\"+s1);
            QFile file2("F:\\清理\\视频\\encvideo\\"+QString::number(i)+"dec.mp4");
            if(!file1.open(QIODevice::ReadOnly))
            {
                qDebug()<<"error open file1";
            };

            if(!file2.open(QIODevice::WriteOnly))
            {
                qDebug()<<"error open file2";
            }

            while(!file1.atEnd())
            {
                QByteArray m=file1.read(1025);
                m.remove(m.size()-1,1);

                file2.write(m);
                qDebug()<<"i";
            }
            file1.close();
            file2.close();
            //  if((fileInfo.size()!=0)&&)
            std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10).arg(fileInfo.fileName()));
            std::cout << std::endl;
        }
    }
    return 0;
}
