#include "board.h"
#include<QPainter>
#include<QDebug>
#include<QRect>
Board::Board(QWidget *parent) : QWidget(parent)
{
    d=40;

    //初始化棋子包括行和列
    //黑方
    for(int i=0;i<32;i++)
    {

       // mycparr[i].SiglePiece.dead=::CParr1[i].dead;
      //  mycparr[i].SiglePiece.number=::CParr1[i].number;
      //  mycparr[i].SiglePiece.type=::CParr1[i].type;
    }

    for(int i=0;i<9;i++)//车马象等没有炮兵
    {
        mycparr[i].col=i;mycparr[i].row=0;
    }

    mycparr[9].col=1;mycparr[10].row=2;//炮

    for(int i=11;i<16;i++)//卒
    {
        mycparr[i].col=(i-11)*2;
        mycparr[i].row=3;
    }

    //红方
    for(int i=16;i<25;i++)//车马象等没有炮兵
    {
        mycparr[i].col=i-16;mycparr[i].row=9;
    }

    mycparr[25].col=1;mycparr[25].row=7;//炮

    for(int i=26;i<32;i++)//兵
    {
        mycparr[i].col=(i-26)*2;
        mycparr[i].row=6;
    }

}

void Board::paintEvent(QPaintEvent *ev)//第一次定义的事件所在窗口打开也会调用这个事件
{
    QPainter p(this);//窗体必须与画笔联系，通过this带初始化的方式
    //画棋盘
    p.setPen(Qt::blue);//将棋盘设置为蓝色
    //画横线
    for(int i=1;i<=10;i++)
        p.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));

    //画竖线，处理显示河界
    for(int i=1;i<=9;i++)
    {
        if((i==1)||(i==9))//只有开始和最后才会画通
        {
            p.drawLine(QPoint(i*d,d),QPoint(i*d,10*d));
        }
        else
        {
            p.drawLine(QPoint(i*d,d),QPoint(i*d,5*d));
            p.drawLine(QPoint(i*d,6*d),QPoint(i*d,10*d));
        }
    }

    //画城堡，设置函数根据行号和列号绘制城堡(开始编号都是0）
    paintCastle(p,2,1);//河界上方
    paintCastle(p,2,7);
    paintCastle(p,3,0);
    paintCastle(p,3,2);
    paintCastle(p,3,4);
    paintCastle(p,3,6);
    paintCastle(p,3,8);

    paintCastle(p,6,0);//河界下方堡垒
    paintCastle(p,6,2);
    paintCastle(p,6,4);
    paintCastle(p,6,6);
    paintCastle(p,6,8);
    paintCastle(p,7,1);
    paintCastle(p,7,7);


    //绘制帅位置附近的九宫格
    p.drawLine(QPoint(4*d,d),QPoint(6*d,3*d));
    p.drawLine(QPoint(6*d,d),QPoint(4*d,3*d));

    p.drawLine(QPoint(4*d,10*d),QPoint(6*d,8*d));
    p.drawLine(QPoint(6*d,10*d),QPoint(4*d,8*d));

    //绘制棋子到棋盘上
    for(int i=0;i<32;i++)
    {
        paintChessPiece(mycparr[i]);
    }
}

void Board::paintCastle(QPainter &p, int row, int col)
{
    int xcor=col*d+d;//横向是x向,向右为正方向
    int ycor=row*d+d;//竖向使y向，向下为正方向，坐标原点在左上角

    QPoint center(xcor,ycor);//由row行数和col列数确定的坐标

    //必须注意去除左右出界的堡垒，方法是当列数为0列、8列分别不能绘制左边和右边
    QPoint origin;
    QPoint end1;
    QPoint end2;

    if(col!=8)
    {
        //绘制右下角
        origin=center+QPoint(d/6,d/6);//确定右下角起点

        end1=origin+QPoint(d/3,0);
        end2=origin+QPoint(0,d/3);
        p.drawLine(origin,end1);
        p.drawLine(origin,end2);

        //绘制右上角
        origin=center+QPoint(d/6,-d/6);

        end1=origin+QPoint(d/3,0);
        end2=origin+QPoint(0,-d/3);
        p.drawLine(origin,end1);
        p.drawLine(origin,end2);
    }



    if(col!=0)
    {
        //绘制左上角
        origin=center+QPoint(-d/6,-d/6);

        end1=origin+QPoint(-d/3,0);
        end2=origin+QPoint(0,-d/3);
        p.drawLine(origin,end1);
        p.drawLine(origin,end2);

        //绘制左下角
        origin=center+QPoint(-d/6,d/6);

        end1=origin+QPoint(-d/3,0);
        end2=origin+QPoint(0,d/3);
        p.drawLine(origin,end1);
        p.drawLine(origin,end2);
    }


}

void Board::paintChessPiece(const MyCPieces &paintcp)
{
    QPainter p(this);
    //绘制圆圈
    if(paintcp.SiglePiece.number<16&&paintcp.SiglePiece.number>=0)
    {
        p.setPen(Qt::black);
    }else
    {
        p.setPen(Qt::red);
    }

    int x=d*paintcp.col+d;//棋子横坐标
    int y=d*paintcp.row+d;//棋子纵坐标

    QPoint center(x,y);

    p.drawEllipse(center,d/2,d/2);


    //绘制文字
    //首先根据类型信息确定文字是什么，枚举的变量取值时不能是汉字
    //CHE,MA,XIANG,SHI,JIANG,SHUAI,PAO,BING,ZU
    QString text="车马象相士将帅炮兵卒";
    QChar c=text.at(paintcp.SiglePiece.type);//QChar就是为了取QString里的当个语言字符而定义的

    //根据row和col定义矩型
    QPoint ptl=center-QPoint(d/2,d/2);//确定矩型左上角坐标
    QPoint ptr=center+QPoint(d/2,d/2);//确定矩型右下角坐标
    QRect qr(ptl,ptr);

    p.drawText(qr,Qt::AlignCenter,(QString)c);//最后一个选项设置居中，注意QChar型数据必须强制类型转换




}
