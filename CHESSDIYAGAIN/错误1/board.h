#ifndef BOARD_H
#define BOARD_H

#include <QtWidgets/QWidget>
#include<QPainter>
#include"chesspieces.h"


struct MyCPieces
{
    int row;
    int col;
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

    int d;
    int row;
    int col;
    MyCPieces mycparr[32];//定义棋子
signals:

public slots:
};

#endif // BOARD_H
