#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPaintEvent>
#include<QLabel>
#include<QPoint>
#include<mybutton.h>
#include<QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
   // void mouseMoveEvent(QMouseEvent *event,const QPoint &mousePos);//错误
    //void event(QEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::Widget *ui;
    QLabel label;
    int i=0;
    int x;
    QPoint p;
    MyButton*mybutton;
    QTimer t1;
};

#endif // WIDGET_H
