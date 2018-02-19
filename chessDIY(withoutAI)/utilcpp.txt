#include "util.h"

int Util::d=40;
Util::Util()
{

}

QPoint Util::   getStonePoint(int row, int col)
{
    int x=col*d+d;
    int y=row*d+d;

    return QPoint(x,y);
}

QRect Util::getStoneRect(int row, int col)
{
    QPoint center=getStonePoint(row,col);
    center-=QPoint(d/2,d/2);
    return QRect(center.x(),center.y(),d,d);
}

 bool Util:: getPlateCord(QPoint pt,int &row,int &col)
 {
     int t[]={-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10};

     int Colindex=pt.x()/(d/2);
     int Rowindex=pt.y()/(d/2);

     if(Rowindex==0)return false;
     if(Colindex==0)return false;

     if(Rowindex>20)return false;
     if(Colindex>18)return false;
     row=t[Rowindex];
     col=t[Colindex];
     return true;

 }
