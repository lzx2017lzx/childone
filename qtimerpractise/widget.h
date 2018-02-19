#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimerEvent>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void timerEvent(QTimerEvent *event);
private:
    int timerid1;
    int timerid2;
    int timerid3;
};

#endif // WIDGET_H
