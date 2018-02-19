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
    void onNew();
    void onSave();
    void onLoad();
    void onBack();

};

#endif // MAINWINDOW_H
