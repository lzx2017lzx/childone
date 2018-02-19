#ifndef MYCLASS1_H
#define MYCLASS1_H

#include <QtCore/QObject>

class MyClass1 : public QObject
{
    Q_OBJECT
public:
    explicit MyClass1(QObject *parent = 0);
    void CalledByOther();
signals:
     void sigFunc();
public slots:

};

#endif // MYCLASS1_H
