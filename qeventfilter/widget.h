#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QEvent>
#include<QPushButton>
#include<QMouseEvent>
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
    //void event(QEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::Widget *ui;
    QPushButton pushbutton;
};

#endif // WIDGET_H
