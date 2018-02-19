#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QDebug>
#include<QMessageBox>
#include<QHostAddress>
#include<QIODevice>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    tcpSocket=new QTcpSocket(this);
    isStart=true;//初始值必须为true否则，无法进入21行的if语句。


    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
            {
                QByteArray buf=tcpSocket->readAll();
               if(true==isStart)
               {
                   isStart=false;

                  // QString str="hello##1024";
                 //  str.section("##",0,0);
                   fileName=QString(buf).section("##",0,0);
                   fileSize=QString(buf).section("##",1,1).toInt();
                   recvSize=0;

                   file.setFileName(fileName);

                   bool isOk=file.open(QIODevice::WriteOnly);
                   if(false==isOk)
                   {
                       qDebug()<<"WriteOnly error 40";
                   }

               }
               else
               {
                   qint64 len=file.write(buf);
                   recvSize+=len;
                   if(recvSize==fileSize)
                   {
                       file.close();
                       QMessageBox::information(this,"完成","文件接收完成");
                        tcpSocket->disconnectFromHost();
                        tcpSocket->close();

                   }
               }

             }
            );

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ClientWidget::on_ButtonConnect_clicked()
{
    QString ip=ui->lineEditIp->text();
    quint16 port=ui->lineEditPort->text().toInt();

    tcpSocket->connectToHost(QHostAddress(ip),port);
    isStart=true;//为了保证某次传输文件成功后，下次也能传输文件成功，必须将isStart设置为true。否则该程序只能传输文件一次。
}
