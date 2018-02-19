#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QFile>
#include<QString>
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
    void sendData();

protected:
    void changeEvent(QEvent *e);


private slots:
    void on_ButtonFile_clicked();

    void on_ButtonSend_clicked();

private:
    Ui::Widget *ui;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

    QFile file;
    QString fileName;
    qint64 fileSize;
    qint64 sendSize;

    QTimer timer;

};

#endif // WIDGET_H
