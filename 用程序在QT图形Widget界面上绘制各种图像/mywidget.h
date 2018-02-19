#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets/QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);
signals:

public slots:
};

#endif // MYWIDGET_H
