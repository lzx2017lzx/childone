#include "board.h"
#include<QPainter>
#include<QDebug>
#include<QRect>
#include<QDataStream>
#include<QFile>
Board::Board(QWidget *parent) : QWidget(parent)
{
    d=40;
    selectRedMove=1;//初始化红棋子先行。
    select=1;//表示此次要求接收的鼠标事件是选子信号，为0表示落子信号
    selectID=-1;//初始化没有选中任何棋子
    steps.clear();//每次打开前先请空
    //初始化棋子包括行和列
    //黑方
    for(int i=0;i<32;i++)
    {
        mycparr[i].selectstate=0;//初始化为0；意思是未选中，也可以在构造函数中初始化
        mycparr[i].SiglePiece.dead=CParr[i].dead;
        mycparr[i].SiglePiece.number=CParr[i].number;
        mycparr[i].SiglePiece.type=CParr[i].type;
    }

    for(int i=0;i<9;i++)//车马象等没有炮兵
    {
        mycparr[i].col=i;mycparr[i].row=0;
    }

    mycparr[9].col=1;mycparr[9].row=2;//炮
    mycparr[10].col=7;mycparr[10].row=2;

    for(int i=11;i<16;i++)//卒
    {
        mycparr[i].col=(i-11)*2;
        mycparr[i].row=3;
    }

    //红方
    for(int i=16;i<25;i++)//车马相等没有炮兵
    {
        mycparr[i].col=i-16;mycparr[i].row=9;
    }

    mycparr[25].col=1;mycparr[25].row=7;//炮
    mycparr[26].col=7;mycparr[26].row=7;
    for(int i=27;i<32;i++)//兵
    {
        mycparr[i].col=(i-27)*2;
        mycparr[i].row=6;
    }


}

void Board::paintEvent(QPaintEvent *ev)//第一次定义的事件所在窗口打开也会调用这个事件
{
    QPainter p(this);//窗体必须与画笔联系，通过this带初始化的方式
    //画棋盘
    QPen pen(Qt::blue,3);
    p.setPen(pen);//将棋盘设置为蓝色
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
    QPen pen(Qt::blue,1,Qt::DashDotLine);
    p.setPen(pen);
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
    if(paintcp.SiglePiece.dead)
    {
        return;
    }
    QPainter p(this);
    //绘制圆圈
    if(paintcp.SiglePiece.number<16&&paintcp.SiglePiece.number>=0)
    {
        QPen pen(Qt::black,4);

        p.setPen(pen);
        // p.setBrush(Qt::gray);

    }else
    {
        QPen pen(Qt::red,4);
        p.setPen(pen);
        //  p.setBrush(Qt::gray);
    }

    int x=d*paintcp.col+d;//棋子横坐标
    int y=d*paintcp.row+d;//棋子纵坐标

    QPoint center(x,y);
    if(paintcp.selectstate==1)//选中的棋子设置画刷为黄色
    {
        p.setBrush(Qt::yellow);
    }
    else
    {
        p.setBrush(Qt::gray);
    }

    p.drawEllipse(center,d/2,d/2);


    //绘制文字
    //首先根据类型信息确定文字是什么，枚举的变量取值时不能是汉字
    //CHE,MA,XIANG,SHI,JIANG,SHUAI,PAO,BING,ZU
    ;
    QString text="车马象相士将帅炮兵卒";
    QChar c=text.at(paintcp.SiglePiece.type);//QChar就是为了取QString里的当个语言字符而定义的

    //根据row和col定义矩型
    QPoint ptl=center-QPoint(d/2,d/2);//确定矩型左上角坐标
    QPoint ptr=center+QPoint(d/2,d/2);//确定矩型右下角坐标
    QRect qr(ptl,ptr);


    p.setFont(QFont("楷体",0.6*d,3));
    // p.set
    p.drawText(qr,Qt::AlignCenter,(QString)c);//最后一个选项设置居中，注意QChar型数据必须强制类型转换




}

void Board::mousePressEvent(QMouseEvent *ev)
{
    //添加保存信息的函数

    // RegretRecord();//如果在这里添加regretrecord信息，就会将所有点击的信息都会添加进入容器。实际上只要将每次移动后的结果添加即可
    QPoint p=ev->pos();//获得鼠标点击位置的坐标
    int row=-1;
    int col=-1;

    FormCor(p,row,col);//获得坐标对应的棋盘的行号和列号
    int PointCPID=GetCPID(row,col);//获得对应的行号和列号处棋子的编号

    qDebug()<<"PointCPID"<<PointCPID;
    if(select==1)
    {
        if(PointCPID<0)//没有选中任何棋子,以后移动的时候，可以选中无棋子的行列？？潜在bug处
        {
            return;
        }
        //轮到红方出棋如果不是红方棋子编号，无论有没有选中棋子都不予处理
        if((selectRedMove==1)&&(PointCPID<16))
        {
            return;
        }

        //轮到黑方出棋如果不是黑方棋子编号，无论有没有选中棋子都不予处理
        if((selectRedMove==0)&&(PointCPID>15))
        {
            return;
        }
        int arrindex=Getarrindex(PointCPID);//由PointCPID获得棋子对应的数组下标
        mycparr[arrindex].selectstate=1;//选中棋子,selectstate变为1

        //其它棋子的selectstate全部变为0
        for(int i=0;i<32;i++)
        {
            if(mycparr[i].SiglePiece.number!=PointCPID)
            {
                mycparr[i].selectstate=0;
            }
        }
        select=!select;//接下来要接收的是落子信号或相反

        selectID=PointCPID;//
        update();
    }else//接收落子信号
    {
        if(PointCPID<0)//表示选中的地方没有棋子，可以改变起子的row、col信息
        {
            int arrindex=Getarrindex(selectID);
            //if(添加能够移动的判断语句)
            if(CanMove(mycparr[arrindex],PointCPID,row,col))
            {
                qDebug()<<"PointCPIDwithoutpieces:"<<PointCPID;
                mycparr[arrindex].row=row;
                mycparr[arrindex].col=col;
                //棋子成功移动之后，恢复起子的颜色
                mycparr[arrindex].selectstate=0;

                select=!select;//接下来要接收的是起子信号或相反
                selectRedMove=!selectRedMove;//轮到黑方起子。
                RegretRecord();//存储棋子移动后棋盘所有重要信息
                update();
                return;
            }

        }else//说明有棋子，而且该棋子可能和起子相同
        {
            int arrindexselect=Getarrindex(selectID);
            int arrindexPointCPID=Getarrindex(PointCPID);
            if((RedColor(selectID))==(RedColor(PointCPID)))//如果起子和落子颜色相同，说明了选择了新的起子
            {

                mycparr[arrindexselect].selectstate=0;//将原先挑选的起子选择状态设置为0；
                selectID=PointCPID;//设置新的起子
                qDebug()<<"set new select pieces succeed.";
                arrindexselect=arrindexPointCPID;//数组下标改变
                mycparr[arrindexselect].selectstate=1;//选中棋子,selectstate变为1

                //其它棋子的selectstate全部变为0
                for(int i=0;i<32;i++)
                {
                    if(mycparr[i].SiglePiece.number!=PointCPID)
                    {
                        mycparr[i].selectstate=0;
                    }
                }
                //   select=!select;//这句不能再添加，因为并没有选择到正确的棋子要保持select不变

                update();
                qDebug()<<"update for new selectpieces succeed";
                return;

            }
            if(CanMove(mycparr[arrindexselect],PointCPID,row,col))//考虑到必须将落子处的棋子和起子进行对比后才能确定能不能移动，最好再添加一个形参，否则就要利用row、col在函数内重新调用求落子处的棋子ID号
            {
              //   RegretRecord();//存储棋子移动后吃子前棋盘所有重要信息
                qDebug()<<"PointCPIDhavepieces:"<<PointCPID;
                mycparr[arrindexselect].row=row;
                mycparr[arrindexselect].col=col;
                //棋子成功移动之后，恢复起子的颜色
                mycparr[arrindexselect].selectstate=0;

                mycparr[arrindexPointCPID].col=-1;//必须将落子处的棋子的行和列变为-1,-1因为它们已经死了
                mycparr[arrindexPointCPID].row=-1;
                mycparr[arrindexPointCPID].SiglePiece.dead=1;//落子处有棋子，且经过canMove判断后可以移动，说明能够杀死对方棋子，让棋子置死，置死的棋子在以后绘图过程中都不会显示，因此必须重新调整绘图函数，添加功能遇到dead是true状态的棋子，一律不绘制到棋盘，mycparr[PointCPID].SiglePiece.dead=0;落子位置棋子被杀，dead应置1
                select=!select;//接下来要接收的是起子信号或相反
                selectRedMove=!selectRedMove;//轮到黑方起子。
                RegretRecord();//存储棋子移动后吃子后棋盘所有重要信息
                update();//更新
                return;
            }

            //return;
            //编写判断有棋子时能否移动
        }





    }

}

void Board::FormCor(QPoint p, int &row, int &col)//将点转换为行号(思想是将复杂的坐标变成简单的坐标)
{
    int ColRowNumber[]={-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
    int xcor=p.x();//获得点的横坐标；
    int ycor=p.y();//获得点的纵坐标；
    int colindex=2*xcor/d;//获得列号对应的下标
    int rowindex=2*ycor/d;//获得行号对应的下标

    col=ColRowNumber[colindex];
    row=ColRowNumber[rowindex];
    qDebug()<<"row"<<row;
    qDebug()<<"col"<<col;
}

//获得行列对应的棋子编号
int Board::GetCPID(int row, int col)
{
    for(int i=0;i<32;i++)
    {
        if((mycparr[i].row==row)&&((mycparr[i].col==col)))//mycparr是棋子数组，每个元素不单包括了一枚棋子的信息，还包括了棋子所在棋盘的行和列信息
        {
            return mycparr[i].SiglePiece.number;//number是棋子的编号
        }
    }
    return -1;
}

int Board::Getarrindex(int CPID)//获得棋子编号对应的数组下标
{
    for(int i=0;i<32;i++)
    {
        if(mycparr[i].SiglePiece.number==CPID)//mycparr是棋子数组，每个元素不单包括了一枚棋子的信息，还包括了棋子所在棋盘的行和列信息
        {
            return i;//i是该棋子对应的棋子数组下标
        }
    }
    return -1;
}


//CanMoveCHE(Type factype);
//CanMoveMA(Type factype);
//CanMoveXIANG(Type factype
//CanMoveSHI(Type factype);
//CanMoveSHUAI(Type factype
//CanMovePAO(Type factype);
//CanMoveBING(Type factype)
bool Board::CanMove(MyCPieces &cpieces,int kpiecesID,int row,int col)
{
    switch(cpieces.SiglePiece.type)
    {
    case Type::CHE:
        return CanMoveCHE(cpieces,kpiecesID,row,col);
        break;
    case Type::MA:
        return CanMoveMA(cpieces,kpiecesID,row,col);
        break;
    case Type::XIANG11:
        return CanMoveXIANG(cpieces,kpiecesID,row,col);
        break;
    case Type::XIANG22:
        return CanMoveXIANG(cpieces,kpiecesID,row,col);
        break;
    case Type::SHI:
        return CanMoveSHI(cpieces,kpiecesID,row,col);
        break;
    case Type::SHUAI:
        return CanMoveSHUAI(cpieces,kpiecesID,row,col);
        break;
    case Type::JIANG:
        return CanMoveSHUAI(cpieces,kpiecesID,row,col);
        break;
    case Type::PAO:
        return CanMovePAO(cpieces,kpiecesID,row,col);
        break;
    case Type::BING:
        return CanMoveBING(cpieces,kpiecesID,row,col);
        break;
    case Type::ZU:
        return CanMoveBING(cpieces,kpiecesID,row,col);
        break;
    default:
        break;
    }
    return 0;
}

//通过比较起子row,col和预落子地方的row,col的row差以及col差
bool Board::CanMoveCHE(MyCPieces &cpieces, int kpiecesID, int row, int col)
{
    int dltarow=qAbs(cpieces.row-row);
    int dltacol=qAbs(cpieces.col-col);
    if((dltarow==0)||(dltacol==0))
    {
        if((GetNumberBT(cpieces,row,col)==0)&&( kpiecesID==-1))//没有棋子,注意GetCPID没有棋子时返回-1；
        {
            return 1;
        }else if((GetNumberBT(cpieces,row,col)==0)&&( kpiecesID!=-1))//预选的落子点有一个棋子,根据前面的情况可以知道，此处是不能出现同一方的棋子
        {
            return 1;
        }
    }

    return 0;
}

bool Board::CanMoveMA(MyCPieces &cpieces, int kpiecesID, int row, int col)
{

    int dltarow=qAbs(cpieces.row-row);
    int dltacol=qAbs(cpieces.col-col);

    qDebug()<<"dltarow"<<dltarow;
    qDebug()<<"dltarow"<<dltacol;
    //考虑正负号
    //dltarow=1,dltacol=2,马脚位置是cpieces.row,两col之间;或dltarow=-1,dltacol=2,马脚位置
    //是cpiece.row,两col之间;或dltarow=1,dltacol=-2,马脚位置是cpiece.row,两col之间;或dltarow
    //=2,dltacol=1,马脚位置是cpieces.col,两row之间;或dltarow=2,dltacol=-1,马脚位置是cpieces.col,两row之间
    //或dltarow=-2,dltacol=1,马脚位置是cpiece.col,两row之间;或dltarow=-2,dltacol=-1,马脚位置是cpieces.col，
    //两row之间

    //筛选所有能走的情况，综合可知当dltarow=1,dltacol=2;马脚位置cpieces.row和两col之间位置没有棋子，即可跳转；
    //dltarow=2,dltacol=1;马脚位置cpieces.col和两row之间位置没有棋子，即可跳转，kpiecesID必然不是同一方的棋子。
    if((dltarow==1)&&(dltacol==2)&&(GetCPID(cpieces.row,(cpieces.col+col)/2)==-1))//GetCPID函数返回-1表示没有棋子
    {
        return 1;
    }

    if((dltarow==2)&&(dltacol==1)&&(GetCPID((cpieces.row+row)/2,cpieces.col)==-1))//GetCPID函数返回-1表示没有棋子,if((dltarow==2)&&(dltacol==1)&&!(GetCPID(cpieces.col,(cpieces.row+row)/2)==-1))参数的顺序弄反了
    {
        return 1;
    }

    return 0;
}

bool Board::CanMoveXIANG(MyCPieces &cpieces, int kpiecesID, int row, int col)
{
    int dltarow=qAbs(cpieces.row-row);
    int dltacol=qAbs(cpieces.col-col);

    qDebug()<<"dltarow"<<dltarow;
    qDebug()<<"dltarow"<<dltacol;
    //横向移动两个单位，竖向移动两个单位，且中间没有象脚就能通过
    if((dltarow==2)&&(dltacol==2)&&(GetCPID((cpieces.row+row)/2,(cpieces.col+col)/2)==-1))// if((dltarow==2)&&(dltacol==2)&&(GetCPID((cpieces.col+col)/2,(cpieces.row+row)/2)==-1)),参数的顺序不对
    {
        return 1;
    }
    return 0;
}

bool Board::CanMoveSHI(MyCPieces &cpieces, int kpiecesID, int row, int col)
{
    if(col>5||col<3)//仕的活动范围在九宫格内
        return 0;
    int dltarow=qAbs(cpieces.row-row);
    int dltacol=qAbs(cpieces.col-col);

    qDebug()<<"dltarow"<<dltarow;
    qDebug()<<"dltarow"<<dltacol;
    //当仕的行和列的变化绝对值是1，时，才能移动，且如果是红方row不能大于第九行，不能小于第七行；如果是黑方row不能大于第2行。所点的落子位置col都在第四列和第六列之间
    if((cpieces.SiglePiece.number>15)&&(cpieces.SiglePiece.number<32))//说明是红方
    {
        if((dltarow==1)&&(dltacol==1)&&((row<10)&&(row>6)))//且仕的活动范围在九宫格内
        {
            return 1;
        }
    }

    if((cpieces.SiglePiece.number>=0)&&(cpieces.SiglePiece.number<16))
    {
        if((dltarow==1)&&(dltacol==1)&&((row<3)&&(row>-1)))//且仕的活动范围在九宫格内
        {
            return 1;
        }
    }

    return 0;
}

bool Board::CanMoveSHUAI(MyCPieces &cpieces,int kpiecesID, int row, int col)
{
    if(col>5||col<3)
        return 0;
    int dltarow=qAbs(cpieces.row-row);
    int dltacol=qAbs(cpieces.col-col);

    qDebug()<<"dltarow"<<dltarow;
    qDebug()<<"dltarow"<<dltacol;
    //返回真的前提条件是dltarow和dltacol之和必须等于1
    if((cpieces.SiglePiece.number>15)&&(cpieces.SiglePiece.number<32))//说明是红方
    {
        if(((dltarow+dltacol)==1)&&((row<10)&&(row>6)))//且将帅的活动范围在九宫格内
        {
            return 1;
        }
    }

    if((cpieces.SiglePiece.number>=0)&&(cpieces.SiglePiece.number<16))
    {
        if(((dltarow+dltacol)==1)&&((row<3)&&(row>-1)))//且将帅的活动范围在九宫格内
        {
            return 1;
        }
    }

    return 0;
}

bool Board::CanMovePAO(MyCPieces &cpieces, int kpiecesID, int row, int col)
{
    //首先所选的落点必须和起子在同一横向或在同一竖向和车类似
    //其次是中间必须有点也能移动，中间无点也能移动
    int dltarow=qAbs(cpieces.row-row);
    int dltacol=qAbs(cpieces.col-col);
    qDebug()<<"dltarow"<<dltarow;
    qDebug()<<"dltarow"<<dltacol;
    if((dltarow==0)||(dltacol==0))
    {
        qDebug()<<"GetNumberBT(cpieces.row,col):"<<GetNumberBT(cpieces,row,col);
        qDebug()<<"kpiecesID:"<<kpiecesID;
        qDebug()<<"row="<<row;
        qDebug()<<"col="<<col;
        if((GetNumberBT(cpieces,row,col)==0)&&( kpiecesID==-1))//没有棋子,注意GetCPID没有棋子时返回-1；
        {
            return 1;
        }else if((GetNumberBT(cpieces,row,col)==1)&&( kpiecesID!=-1))//预选的落子点有一个棋子,而且它们之间也有一个棋子,可以移动
        {
            return 1;
        }
    }

    return 0;

}

bool Board::CanMoveBING(MyCPieces &cpieces, int kpiecesID, int row, int col)
{
    //兵不能后退，即如果是红方cpieces.row-row不能小于零，如果是黑方cpieces.row-row不能大于零
    //兵每一步都只能走一步即dltarow=1，dltacol=1;
    //兵没有过河前只能前进即如果是红方row>4时且row<=6，只能cpieces.row-row=1;兵才能移动；如果是黑方
    //row<5时且row>2，只能cpieces.row-row=-1;卒才能移动
    // 兵过河以后只能向左右或向前移动，即如果是红方row>-1且row<5,必须满足cpieces.row-row=1或dltacol=1;
    //如果是黑方，当row>5且row<10时，必须满足cpieces.row-row=-1或dltcol=1,才能移动

    int dltacol=qAbs(cpieces.col-col);
    int dltarow=qAbs(cpieces.row-row);

    qDebug()<<"dltarow"<<dltarow;
    qDebug()<<"dltarow"<<dltacol;
    if((dltarow==0)||(dltacol==0))//保证兵每次只能走横向或竖向
    {
        if((cpieces.SiglePiece.number>15)&&(cpieces.SiglePiece.number<32))//说明是红方
        {
            if((((row>4)&&(row<7))&&(cpieces.row-row==1))||(((row>-1)&&(row<5))&&((cpieces.row-row==1)||(dltacol==1))))//且将帅的活动范围在九宫格内
            {
                return 1;
            }
        }

        if((cpieces.SiglePiece.number>=0)&&(cpieces.SiglePiece.number<16))//说明是黑方
        {
            if((((row>2)&&(row<5))&&(cpieces.row-row==-1))||(((row>5)&&(row<10))&&((cpieces.row-row==-1)||(dltacol==1))))//且将帅的活动范围在九宫格内
            {
                return 1;
            }
        }
    }
    return 0;
}


//获得在直线上的两点之间的棋子个数,总的思路是慢慢增加row，并用GetCPID判断有没有棋子(类似暴力破解)
//不包括两端点
int Board::GetNumberBT(MyCPieces &cpieces,int row, int col)
{
    int ret=0;//记录棋子的个数
    int temp1=0;//用来记录最小的行号或列号
    int temp2=0;//用来记录最大的行号或列号
    if(cpieces.col==col)
    {
        if(cpieces.row>row)
        {
            temp1=row+1;
            temp2=cpieces.row;
        }else
        {
            temp1=cpieces.row+1;
            temp2=row;
        }
        for(;temp1<temp2;temp1++)
        {
            if(GetCPID(temp1,col)!=-1)//说明没有棋子
            {
                ret++;
            }
        }
        qDebug()<<"GetNumberBT:"<<ret;
        return ret;
    }else
    {
        if(cpieces.col>col)
        {
            temp1=col+1;
            temp2=cpieces.col;
        }else
        {
            temp1=cpieces.col+1;
            temp2=col;
        }
        for(;temp1<temp2;temp1++)
        {
            if(GetCPID(row,temp1)!=-1)//说明有棋子,此处参数是row和temp1，而不是temp1和col
            {
                ret++;
            }
        }
        return ret;
        qDebug()<<"ret:"<<ret;
    }
    qDebug()<<"ret:"<<ret;
    return 0;

}

//判断红方还是黑方的棋子,调用函数前要判断selectID有没有等于-1；-1表示没有棋子
bool Board::RedColor(int selectID)
{
    if((selectID<16)&&(selectID>-1))
    {
        return 0;
    }else
    {
        return 1;//红方
    }
}



void Board::save(QString filename)
{
    QFile file(filename);
    file.open(QFile::WriteOnly);

    QDataStream ds(&file);

    //mycparr[32];  bool selectRedMove;//控制选择要下棋的一方，为1表示轮到红方下棋；为0表示轮到黑方下棋。(方法是，第一次点击选择要下棋的一方的棋子，不允许选择另一方棋子，如果选择到另一方棋子，鼠标事件选中的棋子与根据electredmove提前设置好的值而判断出要走的棋子编号进行比较得出能不能选中的结果，选中以后，应该要求改变棋子的颜色

    // int selectID;//选中的棋子的ID。
    // bool select;
    //    struct CPieces
    //    {
    //        //int row;//行号
    //        // int col;//列号
    //        int number;//总共32个棋子，number用来表示棋子的编号，其中前16个是黑方(0-15)，后16个(16-31)是红方,实际上这个数据未被程序使用，只是为了增加可读性
    //        Type type;//存储棋子的文字信息的类型
    //        bool dead;//所有的事物都应该有存在和不存在两种状态,初始化都是活的

    //    };

    //    struct MyCPieces
    //    {
    //        int row;
    //        int col;
    //        bool selectstate;//设置选中状态信息
    //        CPieces SiglePiece;
    //    };
    ds<<this->selectRedMove<<this->selectID<<this->select;
    for(int i=0;i<32;i++)
    {
        int type=mycparr[i].SiglePiece.type;
        ds<<mycparr[i].row<<mycparr[i].col<<mycparr[i].selectstate<<mycparr[i].SiglePiece.dead<<mycparr[i].SiglePiece.number<<type;
    }

    //存储步骤信息
    //steps stemp;
    for(auto it:steps)
    {
        ds<<it.selectIDstep<<it.selectRedMovestep<<it.selectstep;
        for(int i=0;i<32;i++)
        {
            int type=it.mycparrstep[i].SiglePiece.type;
            ds<<it.mycparrstep[i].col<<it.mycparrstep[i].row<<it.mycparrstep[i].selectstate
             <<it.mycparrstep[i].SiglePiece.dead<<it.mycparrstep[i].SiglePiece.number<<type;
            qDebug()<<"steps 存储信息works";
        }
    }
    file.close();

}

void Board::open(QString filename)
{
    QFile file(filename);
    file.open(QFile::ReadOnly);

    QDataStream ds(&file);

    //mycparr[32];  bool selectRedMove;//控制选择要下棋的一方，为1表示轮到红方下棋；为0表示轮到黑方下棋。(方法是，第一次点击选择要下棋的一方的棋子，不允许选择另一方棋子，如果选择到另一方棋子，鼠标事件选中的棋子与根据electredmove提前设置好的值而判断出要走的棋子编号进行比较得出能不能选中的结果，选中以后，应该要求改变棋子的颜色

    // int selectID;//选中的棋子的ID。
    // bool select;
    //    struct CPieces
    //    {
    //        //int row;//行号
    //        // int col;//列号
    //        int number;//总共32个棋子，number用来表示棋子的编号，其中前16个是黑方(0-15)，后16个(16-31)是红方,实际上这个数据未被程序使用，只是为了增加可读性
    //        Type type;//存储棋子的文字信息的类型
    //        bool dead;//所有的事物都应该有存在和不存在两种状态,初始化都是活的

    //    };

    //    struct MyCPieces
    //    {
    //        int row;
    //        int col;
    //        bool selectstate;//设置选中状态信息
    //        CPieces SiglePiece;
    //    };
    ds>>this->selectRedMove>>this->selectID>>this->select;
    for(int i=0;i<32;i++)
    {
        int type;

        ds>>mycparr[i].row>>mycparr[i].col>>mycparr[i].selectstate>>mycparr[i].SiglePiece.dead>>mycparr[i].SiglePiece.number>>type;//QDatastream<<和>>操作元素顺序不对。
        mycparr[i].SiglePiece.type=(Type)type;
    }

    //录入步骤信息

    steps.clear();//录入前先请空

    while(1)
    {
        Step stemp;
        ds>>stemp.selectIDstep<<stemp.selectRedMovestep<<stemp.selectstep;
        for(int i=0;i<32;i++)
        {
            int type;
            ds>>stemp.mycparrstep[i].col>>stemp.mycparrstep[i].row>>stemp.mycparrstep[i].selectstate
                    >>stemp.mycparrstep[i].SiglePiece.dead>>stemp.mycparrstep[i].SiglePiece.number<<type;
            stemp.mycparrstep[i].SiglePiece.type=(Type)type;
            qDebug()<<"ds 读入信息works.";
        }
        steps.push_back(stemp);
        if(ds.atEnd())
        {
            qDebug()<<"ds at end works.";
            break;
        }
    }
    file.close();
}

void Board::RegretRecord()
{
    Step stemp;
    stemp.selectIDstep=this->selectID;
    stemp.selectRedMovestep=this->selectRedMove;
    stemp.selectstep=this->select;
    for(int i=0;i<32;i++)
    {
        stemp.mycparrstep[i].col=this->mycparr[i].col;
        stemp.mycparrstep[i].row=this->mycparr[i].row;
        stemp.mycparrstep[i].selectstate=this->mycparr[i].selectstate;
        stemp.mycparrstep[i].SiglePiece=this->mycparr[i].SiglePiece;
    }
    steps.push_back(stemp);
    qDebug()<<"steps.size()"<<steps.size();
}
void Board::Goback()
{

    Step stemp;
    if(steps.isEmpty())
    {
        qDebug()<<"steps is empty";
        return;
    }
    stemp=steps.takeLast();


    this->selectRedMove=stemp.selectRedMovestep;

    this->selectID=stemp.selectIDstep;
    this->select=stemp.selectstep;
    for(int i=0;i<32;i++)
    {
        this->mycparr[i].col= stemp.mycparrstep[i].col;
        this->mycparr[i].row=stemp.mycparrstep[i].row;
        // this->mycparr[i].selectstate=stemp.mycparrstep[i].selectstate;
        this->mycparr[i].selectstate=0;
        this->mycparr[i].SiglePiece=stemp.mycparrstep[i].SiglePiece;
        if(i==31)
        qDebug()<<"goback works.";
    }
    qDebug()<<"before pop_back().works";
    steps.pop_back();
    qDebug()<<"pop_back().works";
    qDebug()<<"selectRedMove"<<this->selectRedMove;
    qDebug()<<"stemp.selectRedMovestep"<<stemp.selectRedMovestep;
   qDebug()<<"steps.size()"<<steps.size();
    if(this->selectRedMove==stemp.selectRedMovestep)
    {
        if(steps.isEmpty())
        {
            update();
            return;
        }
        qDebug()<<"get into the circle";
        stemp=steps.takeLast();
        this->selectRedMove=stemp.selectRedMovestep;
        this->selectID=stemp.selectIDstep;
        this->select=stemp.selectstep;
        for(int i=0;i<32;i++)
        {
            this->mycparr[i].col= stemp.mycparrstep[i].col;
            this->mycparr[i].row=stemp.mycparrstep[i].row;
            this->mycparr[i].selectstate=0;
            this->mycparr[i].SiglePiece=stemp.mycparrstep[i].SiglePiece;
            if(i==31)
            qDebug()<<"goback works.";
        }
        qDebug()<<"before pop_back().works";
        qDebug()<<"steps.size()"<<steps.size();
        steps.pop_back();
        qDebug()<<"after pop_back().works";
    }
    update();
    ;
}
