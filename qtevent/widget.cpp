#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QDebug>
#include<QMovie>
#include<QBitmap>
#include<QPicture>
#include<QMouseEvent>
#include<QThread>
#include<QTimer>
#include<QPalette>
#include<QPixmap>
#include<QBrush>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setFixedHeight(300);
    this->setFixedWidth(500);//设置固定窗口大小

    QPalette palette;
    QImage image;
    image.load(":/new/prefix1/image/8.jpg");
    image.setPixel(500,300,4);
   QBrush brush(image);
   palette.setBrush(this->backgroundRole(),brush);

   this->setPalette(palette);
#if 0
    QPalette palette;
   // QImage image;
   // image.load(":/new/prefix1/image/7.jpg");

    QPixmap pixmap(this->height(),this->width());
    qDebug()<<"this->width"<<this->width();
    pixmap.load(":/new/prefix1/image/8.jpg");
   // pixmap.setDevicePixelRatio(image.size()/this->size());
   pixmap.setDevicePixelRatio(0.4);
   palette.setBrush(this->backgroundRole(),QBrush(pixmap));

   this->setPalette(palette);
#endif
    //this->setAutoFillBackground(true);
    //    mybutton=new MyButton(this);
    //    mybutton->setText("A");
//    this->setStyleSheet("QWidget{"
//                        "border-image:url(:/new/prefix1/image/7.jpg);"
//                        ""
//                        ""
//                        "}");//为什么这里不是为widget窗口设置背景
    x=0;

    this->setStyleSheet("border-image:url(:/new/prefix1/image/7.jpg)");
    t1.start(1000000);

    //    connect(mybutton,&QPushButton::clicked,
    //            [=]()
    //    {
    //        x+=20;
    //        QString str;
    //        str=str.number(x);
    //        mybutton->setText(str);
    //        qDebug()<<"x"<<x;
    //    }
    //    );
    ui->setupUi(this);
    label.setParent(this);
    i=0;
    x=0;
    //update();
    ui->pushButton->setMouseTracking(true);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    ui->pushButton->installEventFilter(this);
    this->installEventFilter(this);
#if 0
    //绘制好的picture.jpg不能在本地用照片编辑器打开，只能再次加载到程序，并用picture设备绘制在程序运行的窗口，才能看到图片

    QPicture picture;
    QPainter p;
    p.begin(&picture);

    p.drawPixmap(0,0,80,80,QPixmap("../res/qq.png"));
    p.drawLine(50,50,150,50);
    p.end();

    picture.save("../picture.jpg");
#endif

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



void Widget::on_pushButton_clicked()
{
    //按一次按钮gif图像移动
    //问题:如何在窗口显示gif，通过QLabel标签
    //  if(t1.isActive()==true)

    {
        x+=1;
        //  QThread::sleep(1000);

        QString str;
        str=str.number(x);
        ui->pushButton->setText(str);
        qDebug()<<"x"<<x;
    }
    update();
#if 0

    QMovie*movie=new QMovie(":/new/prefix1/image/1.gif");
    // QMovie*movie=new QMovie("../res/1.gif");
    label.setMovie(movie);
    label.setGeometry(x,0,200,200);

    movie->start();
#endif
#if 0
    QPainter p;
    p.begin(this);
    //  p.drawPixmap(0,0,width(),height(),QPixmap("../res/qq.png"));//有效果，必须将png文件放在编写的.cpp文件的上级目录，放在当前目录是显示不出的。
    // p.drawPixmap(0,0,width(),height(),QPixmap("./qq.png"));没有效果
    //p.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/image/8.jpg"));//有效果可直接从资源中获得jpg
    // p.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/image/1.gif"));//有效果可直接从资源中获得jpg
    // p.drawPixmap(rect(),QPixmap("./qq.png"));:/new/prefix1/image/8.jpg
    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor(14,9,234));
    pen.setStyle(Qt::DashLine);
    p.setPen(pen);
    QBrush brush;

    //QImage image("../res/1.gif");image是图像对象不是动态图对象
    QImage image("../res/qq.png");

    brush.setTextureImage(image);
    // brush.setTextureImage(QImage("../res/qq.png"));
    // brush.setColor(Qt::red);
    // brush.setStyle(Qt::Dense1Pattern);

    p.setBrush(brush);
    p.drawLine(50,50,150,50);
    p.drawRect(150,150,100,50);
    p.drawEllipse(QPoint(150,150),50,25);

    // p.drawRect(0,0,this->width(),this->height());

    p.end();
     qDebug()<<"p works";
#endif

}

void Widget::paintEvent(QPaintEvent *)
{
   // i++;
   // qDebug()<<"paint works"<<i;
#if 0
    QPainter p;
    p.begin(this);
    //  p.drawPixmap(0,0,width(),height(),QPixmap("../res/qq.png"));//有效果，必须将png文件放在编写的.cpp文件的上级目录，放在当前目录是显示不出的。
    // p.drawPixmap(0,0,width(),height(),QPixmap("./qq.png"));没有效果
    //p.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/image/8.jpg"));//有效果可直接从资源中获得jpg
    // p.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/image/1.gif"));//有效果可直接从资源中获得jpg
    // p.drawPixmap(rect(),QPixmap("./qq.png"));:/new/prefix1/image/8.jpg
    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor(14,9,234));
    pen.setStyle(Qt::DashLine);
    p.setPen(pen);
    QBrush brush;

    //QImage image("../res/1.gif");image是图像对象不是动态图对象
    QImage image("../res/qq.png");

    brush.setTextureImage(image);
    // brush.setTextureImage(QImage("../res/qq.png"));
    // brush.setColor(Qt::red);
    // brush.setStyle(Qt::Dense1Pattern);

    p.setBrush(brush);
    p.drawLine(50,50,150,50);
    p.drawRect(150,150,100,50);
    p.drawEllipse(QPoint(150,150),50,25);

    // p.drawRect(0,0,this->width(),this->height());

    p.end();
#endif

#if 0
    QPainter p(this);
    p.drawPixmap(0,0,QPixmap("../res/qq.png"));


    QBitmap bitmap;
    bitmap.load("../res/qq.png");
    p.drawPixmap(0,200,bitmap);
#endif

#if 0
    QPixmap pixmap(400,300);
    QPainter p(&pixmap);

    p.fillRect(0,0,400,300,QBrush(Qt::blue));
    p.drawPixmap(0,0,80,80,QPixmap(":/new/prefix1/image/8.jpg"));

    pixmap.save("../pixmap.jpg");
#endif
#if 0
    QImage image(400,300,QImage::Format_ARGB32);
    QPainter p;
    p.begin(&image);
    p.drawPixmap(0,0,400,300,QPixmap(":/new/prefix1/image/8.jpg"));//可以放大缩小原图片

    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            image.setPixel(QPoint(i,j),qRgb(0,255,0));
            qDebug()<<image.pixel(QPoint(i,j));
        }
    }

    p.end();
    image.save("../image.jpg");
#endif

#if 0
    QPicture pic;
    pic.load("../picture.jpg");
    QPainter p;
    p.begin(this);
    p.drawPicture(0,0,pic);
    p.end();
#endif
}

void Widget::mousePressEvent(QMouseEvent *event)
{

    if(event->button()==Qt::RightButton)
    {
        qDebug()<<"right";
        close();
    }else if(event->button()==Qt::LeftButton)
    {
        qDebug()<<"left";
        p=event->globalPos()-this->frameGeometry().topLeft();
        //event->Drop();
    }
}
//void QAbstract3DInputHandler::mouseMoveEvent(QMouseEvent *event, const QPoint &mousePos)

void Widget::mouseMoveEvent(QMouseEvent *event)
//void Widget::mouseMoveEvent(QMouseEvent *event,const QPoint &mousePos)//错误用法
{
#if 1
    if(event->buttons()&Qt::LeftButton)
    {
        //qDebug()<<"mousePos:"<<mousePos.x()<<mousePos.y();
        qDebug()<<"p:"<<p.x()<<p.y();
        move(event->globalPos()-p);
        qDebug()<<"event->globalPos()-p";
    }
#endif
#if 0
    // 错误用法
    if(event->buttons()==Qt::LeftButton)
    {
        qDebug()<<"mouseMoveEvent works";
        move(event->globalPos()-p);
    }
#endif

}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->pushButton)
    {

    //    on_pushButton_clicked();这句放在这里是不对的，因为事件过滤器只要让ui->pushButton捕捉到信号，就一定会调用这句，要知道程序是在不断刷新的，只有当鼠标按下时，才算点击.
        //所以将这句放到点击处就可以。
        QMouseEvent *env=static_cast<QMouseEvent*>(event);
        if(event->type()==QEvent::MouseMove)
        {

            mouseMoveEvent(env);
            ui->pushButton->setText(QString("button Mouse move:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }

        if(event->type()==QEvent::MouseButtonPress)
        {

            QPalette palette;
           // QImage image;
           // image.load(":/new/prefix1/image/8.jpg");
            QPixmap pixmap(this->width(),this->height());
            pixmap.load(":/new/prefix1/image/8.jpg");
           // pixmap.setDevicePixelRatio(image.size()/this->size());
         //   pixmap.setDevicePixelRatio(1);
           palette.setBrush(this->backgroundRole(),QBrush(pixmap));

           this->setPalette(palette);
          // this->autoFillBackground();
         //  this->setAutoFillBackground(true);
           this->show();
            mousePressEvent(env);
            on_pushButton_clicked();
            ui->pushButton->setText(QString("button Mouse press:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }

        if(event->type()==QEvent::MouseButtonRelease)
        {

            ui->pushButton->setText(QString("button MouseButtonRelease:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }

        if(event->type()==QEvent::Timer)
        {

            return true;
        }

    }
    else if(watched==this)
    {
        //  qDebug()<<".....";
        QMouseEvent *env=static_cast<QMouseEvent*>(event);
        if(event->type()==QEvent::MouseMove)
        {

            mouseMoveEvent(env);
            ui->pushButton->setText(QString("Mouse move:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }

        if(event->type()==QEvent::MouseButtonPress)
        {
            mousePressEvent(env);
            ui->pushButton->setText(QString("Mouse press:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }

        if(event->type()==QEvent::MouseButtonRelease)
        {
            ui->pushButton->setText(QString("MouseButtonRelease:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }

        if(event->type()==QEvent::Timer)
        {
            return true;
        }
    }

    return QWidget::eventFilter(watched,event);



}

