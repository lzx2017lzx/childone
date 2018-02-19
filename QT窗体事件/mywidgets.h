#ifndef MYWIDGETS_H
#define MYWIDGETS_H

#include <QtWidgets/QWidget>
#include<QLabel>
class MyWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidgets(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *ev);
    void keyPressEvent(QKeyEvent *ev);
    void paintEvent(QPaintEvent *ev);
     void mouseReleaseEvent(QMouseEvent *ev);
     void mouseMoveEvent(QMouseEvent *ev);
    void timerEvent(QTimerEvent *ev);
    int t1;
    int t2;
    QLabel *label;
    void labelshow();
    QLabel *label1;
    bool event(QEvent *ev);
#if 0
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void keyPressEvent(QKeyEvent *ev);
    void resizeEvent(QResizeEvent *ev);
    void closeEvent(QCloseEvent *ev);
    void focusInEvent(QFocusEvent*ev);
    void focusOutEvent(QFocusEvent *ev);
#endif


signals:

public slots:
};

#endif // MYWIDGETS_H
