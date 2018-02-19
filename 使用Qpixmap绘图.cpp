#include<QApplication>
#include<QPixmap>
#include<QPainter>
//不展现图片，但是绘制保存图片。
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    QPixmap pixmap(800,600);

    QPainter p;
    p.begin(&pixmap);

    p.setPen(Qt::NoPen);
    p.setBrush(Qt::white);
    p.drawRect(0,0,800,600);

    p.setPen(QPen());
    p.drawLine(QPoint(0,0),QPoint(100,100));

    p.end();
    pixmap.save("./2.jpg");

    return app.exec();
}
