#include "stone.h"

Stone::Stone():d(Util::d)
{
    dead=false;

}

void Stone::draw(QPainter &p,int selectId)
{
    if(dead)return;
    //1、画圆
    //2、画字
    //p.drawEllipse();
    //画圆
    QPoint center=Util::getStonePoint(row,col);
    p.setPen(QPen(Qt::black));
    if(id==selectId)
    {
         p.setBrush(Qt::yellow);
    }
   else
    {
         p.setBrush(Qt::gray);
    }

    p.drawEllipse(center,d/2,d/2);

    // 画字
    QString text="帅仕相马车炮兵将仕相马车炮卒";
    int index=7*(id>16)+(int)type;//type是枚举类型变量实际上是整型，通过这种方法可以实现根据枚举类型匹配字符串中相应的文字的功能
    QChar ch=text.at(index);

    p.setFont(QFont("宋体",d/2));
    if(id<16)
    {
        p.setPen(QPen(Qt::red));
    }
    else
    {
        p.setPen(QPen(Qt::black));
    }
    p.drawText(Util::getStoneRect(row,col),Qt::AlignCenter,QString(ch));

}
