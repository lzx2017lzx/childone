#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public:
    QPushButton pushbutton;
};

#endif // WIDGET_H
