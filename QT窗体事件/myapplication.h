#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QtWidgets/QMainWindow>
#include<QApplication>
class MyApplication : public QApplication
{
    Q_OBJECT
public:
    //explicit MyApplication(QWidget *parent = 0);
    MyApplication(int argc,char *argv[]);
    bool notify(QObject *,QEvent *);
    // bool notify(QWidget *,QEvent *);
signals:

public slots:
};

#endif // MYAPPLICATION_H
