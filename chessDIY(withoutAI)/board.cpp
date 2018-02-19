#include "board.h"
#include<QGridLayout>
#include<QMouseEvent>
#include<QDebug>
#include<QFile>
#include<QDataStream>
Board::Board(QWidget *parent) : QWidget(parent),d(Util::d)
{
    init();
//    struct{
//        Stone::Type type;
//        int row;
//        int col;
//    }p[32]{
//        //红方
//    {Stone::CHE,9,8},
//    {Stone::MA,9,7},
//    {Stone::XIANG,9,6},
//    {Stone::SHI,9,5},
//    {Stone::JIANG,9,4},
//    {Stone::SHI,9,3},
//    {Stone::XIANG,9,2},
//    {Stone::MA,9,1},
//    {Stone::CHE,9,0},

//    {Stone::PAO,7,7},
//    {Stone::PAO,7,1},


//    {Stone::BING,6,0},
//    {Stone::BING,6,2},
//    {Stone::BING,6,4},
//    {Stone::BING,6,6},
//    {Stone::BING,6,8},


//    //黑方
//    {Stone::CHE,0,0},
//    {Stone::MA,0,1},
//    {Stone::XIANG,0,2},
//    {Stone::SHI,0,3},
//    {Stone::JIANG,0,4},
//    {Stone::SHI,0,5},
//    {Stone::XIANG,0,6},
//    {Stone::MA,0,7},
//    {Stone::CHE,0,8},

//    {Stone::PAO,2,1},
//    {Stone::PAO,2,7},


//    {Stone::BING,3,0},
//    {Stone::BING,3,2},
//    {Stone::BING,3,4},
//    {Stone::BING,3,6},
//    {Stone::BING,3,8},




//};
//    //初始化棋子32个
//    for(int i=0;i<32;i++)
//    {
//        s[i].id=i;
//        s[i].type=p[i].type;
//        s[i].row=p[i].row;
//        s[i].col=p[i].col;
//    }
//    //    s[0].type=Stone::CHE;
//    //    s[0].row=10;
//    //    s[0].col=9;

//    //    d=40;
//    selectId=-1;
//    redTurn =true;
}

void Board::init()
{
    clearSteps();
    struct{
        Stone::Type type;
        int row;
        int col;
    }p[32]{
        //红方
    {Stone::CHE,9,8},
    {Stone::MA,9,7},
    {Stone::XIANG,9,6},
    {Stone::SHI,9,5},
    {Stone::JIANG,9,4},
    {Stone::SHI,9,3},
    {Stone::XIANG,9,2},
    {Stone::MA,9,1},
    {Stone::CHE,9,0},

    {Stone::PAO,7,7},
    {Stone::PAO,7,1},


    {Stone::BING,6,0},
    {Stone::BING,6,2},
    {Stone::BING,6,4},
    {Stone::BING,6,6},
    {Stone::BING,6,8},


    //黑方
    {Stone::CHE,0,0},
    {Stone::MA,0,1},
    {Stone::XIANG,0,2},
    {Stone::SHI,0,3},
    {Stone::JIANG,0,4},
    {Stone::SHI,0,5},
    {Stone::XIANG,0,6},
    {Stone::MA,0,7},
    {Stone::CHE,0,8},

    {Stone::PAO,2,1},
    {Stone::PAO,2,7},


    {Stone::BING,3,0},
    {Stone::BING,3,2},
    {Stone::BING,3,4},
    {Stone::BING,3,6},
    {Stone::BING,3,8},




};
    //初始化棋子32个
    for(int i=0;i<32;i++)
    {
        s[i].id=i;
        s[i].type=p[i].type;
        s[i].row=p[i].row;
        s[i].col=p[i].col;
        s[i].dead=false;
    }
    //    s[0].type=Stone::CHE;
    //    s[0].row=10;
    //    s[0].col=9;

    //    d=40;
    selectId=-1;
    redTurn =true;
}

void Board::save(QString filename)
{
    QFile file(filename);
    file.open(QFile::WriteOnly);

    QDataStream ds(&file);

    ds<<this->selectId<<this->redTurn;
    for(int i=0;i<32;i++)
    {
        int type=(int)s[i].type;
        ds<<s[i].col<<s[i].row<<s[i].id<<s[i].dead<<type;
    }

    ds<<(int)steps.size();
    foreach(Step*step,steps)
    {
        ds<<step->colFrom<<step->colTo<<step->killid<<step->moveid<<step->rowFrom<<step->rowTo;
    }

    file.close();
}

void Board::load(QString filename)
{
    QFile file(filename);
    file.open(QFile::ReadOnly);

    QDataStream ds(&file);

    ds>>this->selectId>>this->redTurn;
    for(int i=0;i<32;i++)
    {
        int type;
        ds>>s[i].col>>s[i].row>>s[i].id>>s[i].dead>>type;
        s[i].type=(Stone::Type)type;
    }

    int size;
    ds>>size;
    for(int i=0;i<size;++i)
    {
        Step *step=new Step;
                ds>>step->colFrom>>step->colTo>>step->killid>>step->moveid>>step->rowFrom>>step->rowTo;
       steps.push_back(step);

    }
    //ds>>steps;
    file.close();
    update();
}

void Board::backOne()//晦棋
{
    if(steps.size()==0)
        return;
    Step *step=steps.last();
    steps.removeLast();

    s[step->moveid].row=step->rowFrom;
    s[step->moveid].col=step->colFrom;

    if(step->killid!=-1)
    {
        s[step->killid].dead=false;
    }
    this->redTurn=!this->redTurn;
    selectId=-1;
    delete step;
    update();
}


void Board::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);

    drawPlate(p);
}

void Board::drawPlate(QPainter &p)
{
    for(int i=1;i<=10;i++)//绘制横线(10条)
    {
        p.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));
        //  p.drawLine(QPoint(d,*d),QPoint(9*d,2*d));
        // p.drawLine(QPoint(i*d,d),QPoint(i*d,9*d));
    }

    for(int i=1;i<=9;i++)//绘制竖线(9条)
    {
        if((i==1)||(i==9))//开始和结尾的竖线必须画通
        {
            p.drawLine(QPoint(i*d,d),QPoint(i*d,10*d));
        }
        else
        {
            p.drawLine(QPoint(i*d,d),QPoint(i*d,5*d));
            p.drawLine(QPoint(i*d,6*d),QPoint(i*d,10*d));
        }
        //if()
        //绘制九宫格
        p.drawLine(QPoint(4*d,d),QPoint(6*d,3*d));
        p.drawLine(QPoint(6*d,d),QPoint(4*d,3*d));

        p.drawLine(QPoint(4*d,10*d),QPoint(6*d,8*d));
        p.drawLine(QPoint(6*d,10*d),QPoint(4*d,8*d));


    }
    //绘制十字架(红 方）
    drawCross(p,2,1);
    drawCross(p,2,7);
    drawCross(p,3,0);
    drawCross(p,3,2);
    drawCross(p,3,4);
    drawCross(p,3,6);
    drawCross(p,3,8);

    //绘制十字架(黑 方）
    drawCross(p,7,1);
    drawCross(p,7,7);
    drawCross(p,6,0);
    drawCross(p,6,2);
    drawCross(p,6,4);
    drawCross(p,6,6);
    drawCross(p,6,8);

    //绘制棋子
    for(int i=0;i<32;i++)
    {
        s[i].draw(p,selectId);
    }

}

//绘制棋盘十字型
void Board::drawCross(QPainter &p, int row, int col)
{
    //    int x=col*d+d;
    //    int y=row*d+d;

    //  QPoint center(x,y);
    QPoint center=Util::getStonePoint(row,col);
    QPoint origin;
    if(col!=8)//保证col==8时不会绘制右边图形
    {
        //右下角绘制
        origin=center+QPoint(d/6,d/6);
        p.drawLine(origin,(origin+QPoint(d/3,0)));
        p.drawLine(origin,(origin+QPoint(0,d/3)));

        //右上角绘制
        origin=center+QPoint(d/6,-d/6);
        p.drawLine(origin,(origin+QPoint(d/3,0)));
        p.drawLine(origin,(origin+QPoint(0,-d/3)));
    }
    //    //右下角绘制
    //    QPoint origin=center+QPoint(d/6,d/6);
    //    p.drawLine(origin,(origin+QPoint(d/2,0)));
    //    p.drawLine(origin,(origin+QPoint(0,d/2)));

    //    //右上角绘制
    //     origin=center+QPoint(d/6,-d/6);
    //    p.drawLine(origin,(origin+QPoint(d/2,0)));
    //    p.drawLine(origin,(origin+QPoint(0,-d/2)));

    if(col!=0)//保证col==0时不会绘制左边图形
    {
        //左下角绘制
        origin=center+QPoint(-d/6,d/6);
        p.drawLine(origin,(origin+QPoint(-d/3,0)));
        p.drawLine(origin,(origin+QPoint(0,d/3)));

        //左上角绘制
        origin=center+QPoint(-d/6,-d/6);
        p.drawLine(origin,(origin+QPoint(-d/3,0)));
        p.drawLine(origin,(origin+QPoint(0,-d/3)));
    }
}

void Board::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::RightButton)
        return;
    qDebug()<<"kk";
    QPoint ptClick=ev->pos();
    int row=-1,col=-1;
    if(!Util::getPlateCord(ptClick,row,col))
    {
        //点到棋盘外作废。
        return;
    }
    qDebug()<<row<<col;

    int clickId=getStoneId(row,col);
    if(selectId==-1)
    {
        selectStone(clickId);
#if 0
        // if((clickId>15)&&redTurn)
        //  {
        //      return;
        //  }

        // if(!redTurn&&clickId<16)
        //  {
        //      return;
        //   }

        if(redTurn!=clickId<16)
        {
            return;
        }
        selectId=clickId;
        update();
#endif
        //return;
    }
    else
    {
        if(clickId!=-1&&(clickId<16==selectId<16))
        {
#if 0
            selectId=clickId;
            update();
#endif
            selectStone(clickId);
            return;
        }
#if 0
        //move
        s[selectId].row=row;
        s[selectId].col=col;
        if(clickId!=-1)
        {
            s[clickId].dead=true;
        }
        update();
        selectId=-1;
        redTurn=!redTurn;
#endif
        if(canMove(selectId,clickId,row,col))
        {
            moveStone(selectId,clickId,row,col);
        }
        ;

    }
}

int Board::getStoneId(int row, int col)
{
    for(int i=0;i<32;i++)
    {
        if((s[i].row==row)&&(s[i].col==col)&&(!s[i].dead))
        {
            return i;
        }
    }
    return -1;
}

void Board::selectStone(int select)
{

    // if((clickId>15)&&redTurn)
    //  {
    //      return;
    //  }

    // if(!redTurn&&clickId<16)
    //  {
    //      return;
    //   }

    if(redTurn!=select<16)
    {
        return;
    }
    selectId=select;
    update();

}

void Board::moveStone(int select,int kill,int row,int col)
{
    addStep(select,kill,row,col);
    //move
    s[select].row=row;
    s[select].col=col;
    if(kill!=-1)
    {
        s[kill].dead=true;
    }

    selectId=-1;
    redTurn=!redTurn;
    update();

}

bool Board::canMove(int select, int kill, int row, int col)
{
    switch(s[select].type)
    {
    case Stone::JIANG:
        return canMoveJiang(select,kill,row,col);
        break;
    case Stone::SHI:
        return canMoveShi(select,kill,row,col);
        break;
    case Stone::XIANG:
        return canMoveXiang(select,kill,row,col);
        break;
    case Stone::MA:
        return canMoveMa(select,kill,row,col);
        break;
    case Stone::PAO:
        return canMovePao(select,kill,row,col);
        break;
    case Stone::BING:
        return canMoveBing(select,kill,row,col);
        break;

    }
    return true;
}



bool Board::canMoveJiang(int select,int kill,int row,int col)
{
    //对面吃
    if(kill!=-1&&s[kill].type==Stone::JIANG)
    {
        int ret=getStoneCount(s[select].row,s[select].col,row,col);
        if(ret==0)
        {
            return true;
        }
    }
    int dRow=qAbs(s[select].row-row);
    int dCol=qAbs(s[select].col-col);
    if(dRow+dCol!=1)
    {
        return false;
    }

    if(col<3||col>5)return false;
    if(s[select].id<16)
    {
        if(row<7||row>9)return false;
    }
    else
    {
        if(row<0||row>2)return false;
    }



    return true;
}

bool Board::canMoveShi(int select,int,int row,int col)
{
    if(col<3||col>5)return false;
    if(s[select].id<16)
    {
        if(row<7||row>9)return false;
    }
    else
    {
        if(row<0||row>2)return false;
    }

    int dRow=qAbs(s[select].row-row);
    int dCol=qAbs(s[select].col-col);

    if(dRow*10+dCol!=11)
    {
        return false;
    }
    return true;
}

bool Board::canMoveXiang(int select,int,int row,int col)
{
    //不能过河
    if(s[select].id<16)
    {
        if(row<5)return false;
    }else
    {
        if(row>4)return false;
    }

    int dRow=qAbs(s[select].row-row);
    int dCol=qAbs(s[select].col-col);
    if(dRow*10+dCol!=22)
    {
        return false;
    }

    int eRow=(s[select].row+row)/2;
    int eCol=(s[select].col+col)/2;
    int eye=getStoneId(eRow,eCol);
    if(eye!=-1)
    {
        return false;
    }
    return true;
}

bool Board::canMoveChe(int select,int,int row,int col)
{
    int ret=getStoneCount(s[select].row,s[select].col,row,col);
    if(ret!=0)return false;
    return true;
}

bool Board::canMoveMa(int select,int ,int row,int col)
{
    int dRow=qAbs(s[select].row-row);
    int dCol=qAbs(s[select].col-col);
    int d=dRow*10+dCol;
    if(d!=21&&d!=12)
    {
        return false;
    }

    if(d==21)
    {
        int eRow=(s[select].row+row)/2;
        int eCol=s[select].col;
        if(getStoneId(eRow,eCol)!=-1)return false;
    }
    else
    {
        int eRow=s[select].row;
        int eCol=(s[select].col+col)/2;
        if(getStoneId(eRow,eCol)!=-1)return false;
    }
    return true;
}

bool Board::canMovePao(int select,int kill,int row,int col)
{
    if(kill==-1)
    {
        int ret=getStoneCount(s[select].row,s[select].col,row,col);
        if(ret!=0)return false;
    }else
    {
        int ret=getStoneCount(s[select].row,s[select].col,row,col);
        if(ret!=1)return false;
    }

    return true;
}

bool Board::canMoveBing(int select,int,int row,int col)
{
    int dRow=qAbs(s[select].row-row);
    int dCol=qAbs(s[select].col-col);
    if(dRow+dCol!=1)
    {
        return false;
    }
    if(s[select].id<16)//下方是红方(开始16个棋子是红方，在河的下方)
    {
        if(row>s[select].row)return false;//后退
        if(s[select].row>=5)//红方没有过河
            if(row==s[select].row)
            {
                return false;
            }
    }
    else//黑色棋子
    {
        if(row<s[select].row)return false;//后退
        if(s[select].row<=4)//红方没有过河
            if(row==s[select].row)
            {
                return false;
            }
    }
    return true;
}
int Board::getStoneCount(int row1,int col1,int row2,int col2)
{
    int ret=0;
    if(row1!=row2&&col1!=col2)return -1;//能运行后面的程序的条件是row1==row2或col1==col2
    if(row1==row2)
    {
        if(col1>col2)
        {
            int tmp=col1;
            col1=col2;
            col2=tmp;
        }
        {
            for(int col=col1+1;col<col2;++col)//加1是指计算棋子之间个数不包含自己
            {
                if(getStoneId(row1,col)!=-1)
                    ret++;
            }
        }
    }
    else
    {
        if(row1>row2)
        {
            int tmp=row1;
            row1=row2;
            row2=tmp;
        }
        for(int row=row1+1;row<row2;row++)
        {
            if(getStoneId(row,col1)!=-1)
                ret++;
        }
    }

    return ret;
}

void Board::addStep(int select, int kill, int row, int col)
{
    Step *step=new Step;
    step->moveid=select;
    step->rowTo=row;
    step->colTo=col;
    step->rowFrom=s[select].row;
    step->colFrom=s[select].col;
    steps.append(step);
}

void Board::clearSteps()
{

    while(steps.size())
    {
        Step *step=steps.first();
        delete step;
        steps.removeFirst();
    }
}
