#ifndef BOARD_H
#define BOARD_H

#include <QtWidgets/QWidget>
#include<QPainter>
#include<QMouseEvent>
#include"chesspieces.h"
enum Type{CHE,MA,XIANG11,XIANG22,SHI,JIANG,SHUAI,PAO,BING,ZU};//用枚举类型归类棋子的文字信息


struct CPieces
{
    //int row;//行号
    // int col;//列号
    int number;//总共32个棋子，number用来表示棋子的编号，其中前16个是黑方(0-15)，后16个(16-31)是红方,实际上这个数据未被程序使用，只是为了增加可读性
    Type type;//存储棋子的文字信息的类型
    bool dead;//所有的事物都应该有存在和不存在两种状态,初始化都是活的

};

struct MyCPieces
{
    int row;
    int col;
    bool selectstate;//设置选中状态信息
    CPieces SiglePiece;
};


class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);

    void paintEvent(QPaintEvent *ev);
    void paintCastle(QPainter&p,int row,int col);//因为城堡和棋盘一般是相同画笔，这里用引用
    void paintChessPiece(const MyCPieces &paintcp);//绘制棋子，参数是棋子信息
    void mousePressEvent(QMouseEvent *ev);//定义鼠标事件
    void FormCor(QPoint p,int &row,int &col);//找到屏幕中的点对应的行号和列号，转换的范围由棋子的面积决定，定义外部参数接收,目的是选中棋子，选中棋子前必须找到点对应的行号和列号
    int GetCPID(int row,int col);//根据鼠标点击事件捕捉到的点对应的行列号获得该点对应的棋子编号，没有棋子，就返回-1.
    int Getarrindex(int CPID);//根据棋子的编号获得棋子对应的数组下标

    bool CanMove(MyCPieces &cpieces,int kpiecesID,int row,int col);//根据棋子类型(车、马等)判断能不能走，如果几个函数功能类似，就应该设置综合程序，用于根据条件调用这几个函数
    //确定棋子能不能走必须考虑到棋子的内的行号和列号，以及落子位置的行号和列号，所以暂时设定单个参数
    //CanMove中必须要判断row、col对应的位置有没有棋子，如果有棋子（肯定是对方棋子)必须决定能否杀死。
    bool CanMoveCHE(MyCPieces &cpieces,int kpiecesID,int row,int col);//共7个
    bool CanMoveMA(MyCPieces &cpieces,int kpiecesID,int row,int col);
    bool CanMoveXIANG(MyCPieces &cpieces,int kpiecesID,int row,int col);//因为type中有XIANG11和XIANG22,但它们的功能是相同的，所以可以被同一个函数调用
    bool CanMoveSHI(MyCPieces &cpieces,int kpiecesID,int row,int col);
    bool CanMoveSHUAI(MyCPieces &cpieces,int kpiecesID,int row,int col);//因为SHUAI和JIANG的功能是相同的，所以可以用同一函数表示其功能
    bool CanMovePAO(MyCPieces &cpieces,int kpiecesID,int row,int col);
    bool CanMoveBING(MyCPieces &cpieces,int kpiecesID,int row,int col);//因为BING和ZU的功能是相同的，所以可以用同一个函数表示

    int GetNumberBT(MyCPieces &cpieces,int row,int col);//获得两个棋子之间的直线上棋子个数

    bool RedColor(int selectID);//根据结点编号判断是红方的还是黑方的,其中1表示红方，0表示黑方




    int d;
    int row;
    int col;
    bool selectRedMove;//控制选择要下棋的一方，为1表示轮到红方下棋；为0表示轮到黑方下棋。(方法是，第一次点击选择要下棋的一方的棋子，不允许选择另一方棋子，如果选择到另一方棋子，鼠标事件选中的棋子与根据electredmove提前设置好的值而判断出要走的棋子编号进行比较得出能不能选中的结果，选中以后，应该要求改变棋子的颜色

    int selectID;//选中的棋子的ID。
    bool select;//select为1表示选中，为0表示没有选中
    //红方在下，黑方在上
    CPieces CParr[32]=
    {
        {0,CHE,0},{1,MA,0},{2,XIANG11,0},{3,SHI,0},{4,JIANG,0},{5,SHI,0},{6,XIANG11,0},{7,MA,0},
        {8,CHE,0},{9,PAO,0},{10,PAO,0},{11,ZU,0},{12,ZU,0},{13,ZU,0},{14,ZU,0},{15,ZU,0},
        {16,CHE,0},{17,MA,0},{18,XIANG22,0},{19,SHI,0},{20,SHUAI,0},{21,SHI,0},{22,XIANG22,0},{23,MA,0},
        {24,CHE,0},{25,PAO,0},{26,PAO,0},{27,BING,0},{28,BING,0},{29,BING,0},{30,BING,0},{31,BING,0}
    };//定义棋子
    MyCPieces mycparr[32];


signals:

public slots:
};

#endif // BOARD_H
