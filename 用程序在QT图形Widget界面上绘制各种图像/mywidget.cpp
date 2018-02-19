#include "mywidget.h"
#include<QPainter>
#include<QPixmap>
#include<QScreen>
#include<QApplication>
#include<QDesktopWidget>
#include<QDebug>
#include<QFont>
#include<QTransform>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}

 void MyWidget::mousePressEvent(QMouseEvent *ev)
 {
     #if 0
     QPixmap pixmap(width(),height());
     QPainter p(&pixmap);

     this->render(&p);
     p.end();

     pixmap.save("./1.png");
#endif
     QScreen *screen=qApp->primaryScreen();
     QDesktopWidget *desktop=qApp->desktop();

     QPixmap pixmap=screen->grabWindow(desktop->winId());
     pixmap.save("./2.png");
     qDebug()<<"pixmap works.";
 }

 void MyWidget::paintEvent(QPaintEvent *ev)
 {
    QPainter p;
    p.begin(this);

   // p.drawText(100,50,"妹子");

    p.drawEllipse(QPoint(200,200),100,50);

   p.setRenderHint(QPainter::Antialiasing);
    p.drawEllipse(QPoint(400,200),200,100);
#if 1
    QPen pen(Qt::red,34,Qt::SolidLine);
    p.setPen(pen);

    p.setBrush(QBrush(Qt::green));

    p.drawLine(QPoint(0,0),QPoint(100,100));
#endif


#if 1
    p.translate(100,100);

//    p.scale(0.5f,0.5f);
//    p.rotate(30);
#endif
 #if 1
    QTransform transform;//设置类对象，对象内数据都是绘制效果的方法
    transform.rotate(30);//旋转效果
    transform.translate(300,100);//相对于x、y偏移的像素距离

    transform.scale(1,1);// 设置图片的大小(参数单位是比例）
    p.setTransform(transform);//设置画笔对象的效果

#endif
#if 1
    p.setPen(QPen(Qt::red));
    p.setBrush(QBrush(Qt::green));
    p.drawRect(QRect(70,30,100,50));
    p.setTransform(QTransform());
    p.setBrush(QBrush(Qt::green));
    p.drawEllipse(QPoint(180,90),100,50);
#endif
#if 1
    QTransform transforml;
    transforml.rotate(-30);
    p.setTransform(transforml,true);

    p.setPen(Qt::red);
    p.setFont(QFont("宋体",80,300,true));
    p.drawText(200,500,"妹子");

   p.drawImage(QPointF(200,100),QImage("./2.png"));
    p.end();
#endif












 }
