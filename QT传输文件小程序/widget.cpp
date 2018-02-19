#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QDebug>
#include<QFileInfo>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpServer=new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any,8888);
    setWindowTitle("服务器端口:8888");
    ui->ButtonFile->setEnabled(false);
    ui->ButtonSend->setEnabled(false);


    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        tcpSocket=tcpServer->nextPendingConnection();
        QString ip=tcpSocket->peerAddress().toString();
        quint16 port=tcpSocket->peerPort();

        QString str=QString("[%1:%2] 成功连接").arg(ip).arg(port);
        ui->textEdit->setText(str);

        ui->ButtonFile->setEnabled(true);



    }

            );
    connect(&timer,&QTimer::timeout,
            [=]()
    {
        timer.stop();

        sendData();
    }


            );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
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

void Widget::on_ButtonFile_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,"open","../");
    if(false==filePath.isEmpty())
    {
        fileName.clear();
        fileSize=0;

        QFileInfo info(filePath);
        fileName=info.fileName();
        fileSize=info.size();

        sendSize=0;

        file.setFileName(filePath);

        bool isOk=file.open(QIODevice::ReadOnly);
        if(false==isOk)
        {
            qDebug()<<"只读方式打开文件失败 77";
        }
        ui->textEdit->append(filePath);

        ui->ButtonFile->setEnabled(false);
        ui->ButtonSend->setEnabled(true);
    }
    else
    {
        qDebug()<<"选择文件路径出错 62";
    }


}

void Widget::on_ButtonSend_clicked()
{
    QString head=QString("%1##%2").arg(fileName).arg(fileSize);


    qint64 len=tcpSocket->write(head.toUtf8());
    qDebug()<<"len:"<<len;
    if(len>0)
    {
        timer.start(50);
    }
    else
    {
        qDebug()<<"头部信息发送失败 110";
        file.close();
        ui->ButtonFile->setEnabled(true);
        ui->ButtonSend->setEnabled(false);
    }

}

void Widget::sendData()
{
    qint64 len=0;
    sendSize=0;
    do
    {
        char buf[4*1024]={0};
        len=0;

        len=file.read(buf,sizeof(buf));
        qDebug()<<"sendData():len:"<<len;
        qDebug()<<"fileSize():len";
       // qDebug()<<fileSize;
        len=tcpSocket->write(buf,len);

        sendSize+=len;
        qDebug()<<"sendSize"<<sendSize;
    }while(len>0);
    qDebug()<<"fileSize:"<<fileSize;
    if(sendSize==fileSize)
    {
        ui->textEdit->append("文件发送完毕");
        file.close();

        tcpSocket->disconnectFromHost();
        tcpSocket->close();

    }
    else
    {
        qDebug()<<"senddata works wrong";
    }
}
