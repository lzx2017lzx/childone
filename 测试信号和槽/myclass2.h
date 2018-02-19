#ifndef MYCLASS2_H
#define MYCLASS2_H

#include <QObject>

class MyClass2 : public QObject
{
    Q_OBJECT
public:
    explicit MyClass2(QObject *parent = 0);
    void CalledByOther();

signals:

public slots:
    void slotFunc();
};

#endif // MYCLASS2_H
