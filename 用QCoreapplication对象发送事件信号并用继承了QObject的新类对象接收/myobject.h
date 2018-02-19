#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QtCore/QObject>
#include<QEvent>
class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = 0);
    bool event(QEvent *event);
signals:

public slots:
};

#endif // MYOBJECT_H
