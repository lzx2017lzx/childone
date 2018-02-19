#include "mainwindow.h"

#include<QToolBar>
#include<QMenuBar>
#include<QStatusBar>
#include<QAction>
#include<QFileDialog>
#include<QDataStream>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->addToolBar("保存");
    QMenuBar*mBar=menuBar();//设置菜单栏

    QMenu*Game=mBar->addMenu("游戏设置(&G)");//在菜单单栏中添加菜单项
    QAction *actionSaveGame=Game->addAction("保存游戏(&S)",this,SLOT(onSave()));//在菜单项中添加保存游戏控件
    QAction *actionUploadGame=Game->addAction("读取游戏(&R)",this,SLOT(onOpen()));//在菜单项中添加读取游戏控件，onOpen是设置的槽函数
    QAction *actionExitGame=Game->addAction("退出游戏(E)",this,SLOT(onExit()));//在菜单项中添加退出游戏控件
    QAction *actionRegretGame=Game->addAction("晦棋(&B)",this,SLOT(onRegret()));//在菜单项中添加晦棋控件
    QToolBar *toolbar=addToolBar("tool");//设置工具栏
    toolbar->addAction(actionSaveGame);
    toolbar->addAction(actionUploadGame);
    toolbar->addAction(actionExitGame);
    toolbar->addAction(actionRegretGame);


    //Board *board=new Board(this);没有将board声明为类mainwindow的成员，造成类成员函数无法访问构造函数中定义的变量board
    board=new Board(this);
    setCentralWidget(board);//设置widget构建在mainwindow中居中布置，这种说法是错误的，而是在菜单栏、工具栏、状态栏以外的空间布置控件


}

void MainWindow::onOpen()
{
    QString filename=QFileDialog::getOpenFileName(this);//打开文件
    if(filename.length()>0)
        board->open(filename);

}

void MainWindow::onSave()
{
    //QString filename=QFileDialog::getOpenFileName(this,"请保存","d:\\","中国象棋文件(*.alfgo)");保存时不能使用getopenfilename，而是getSaveFileName;
    QString filename=QFileDialog::getSaveFileName(this,"请保存","d:\\","中国象棋文件(*.alfgo)");
    if(filename.length()>0)
        board->save(filename);
}

void MainWindow::onExit()
{
    //    int ret=QMessageBox ::question(this,"退出游戏","是否保存退出",
    //   QString("保存信息"),QString("直接退出"));//返回值是0，意味保存信息，返回值是1，意味直接退出
    //    if(0==ret)
    //    {
    //        onSave();
    //    }else if(1==ret)
    //    {
    //        this->close();
    //    }
    //    return;


    QMessageBox QMB;
    int ret=QMB.question(this,"退出游戏","是否保存退出",
                         QString("保存信息"),QString("直接退出"));
  //  QMB.setSizePolicy();
    if(0==ret)
    {
        onSave();
    }else if(1==ret)
    {
        this->close();
    }
    return;

}

void MainWindow::onRegret()
{
    board->Goback();
}









