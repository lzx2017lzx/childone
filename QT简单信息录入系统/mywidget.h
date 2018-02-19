#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets/QWidget>
#include<QHBoxLayout>
#include<QLineEdit>
#include<QPushButton>
#include<QGridLayout>
#include<QLabel>
#include<QString>
#include<QList>
#include<QDebug>
#include<QFile>
#include<QVector>
#include<QDataStream>
#include<string>
#include<vector>
#include"student.h"
using namespace std;
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    QLineEdit *edit1;
    QLineEdit *edit2;
    QLineEdit *edit3;
    //QFile *file;//定义文件指针，用来读写数据、
     void readstream();//定义读文件函数
     QVector<Student>vfile;//定义vector容器用来文件读写
signals:

public slots:
    void writestream();//定义写文件的槽函数

};
#endif // MYWIDGET_H
