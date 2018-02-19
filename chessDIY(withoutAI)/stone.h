#ifndef STONE_H
#define STONE_H

#include<QPainter>
#include"util.h"
class Stone
{
public:
    Stone();

    enum Type{JIANG,SHI,XIANG,MA,CHE,PAO,BING};
    int row;
    int col;
    Type type;
    bool red;
    int id;//0-15 红色 16-31 黑色

    bool dead;
    int &d;
    QString text;

    void draw(QPainter &p,int selectId);//绘制棋子函数
};

#endif // STONE_H
