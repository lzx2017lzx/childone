#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include"board.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

    Board *board;
signals:

public slots:
    void onOpen();
    void onSave();
    void onExit();
    void onRegret();
    void onBegin();
};

#endif // MAINWINDOW_H
