#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QMouseEvent>
#include<QPoint>
class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
signals:

private:
     QPoint p;
public slots:
};

#endif // MYBUTTON_H
