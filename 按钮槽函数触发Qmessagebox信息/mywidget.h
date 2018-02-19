#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets/QWidget>
#include<QMessageBox>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

signals:

public slots:
    void ActivateMessagebox();
};

#endif // MYWIDGET_H
