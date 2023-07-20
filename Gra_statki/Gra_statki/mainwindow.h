#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include "controller.h"


namespace Ui {
class MainWindow;

};
class Controller;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    int tab1[N][N],tab2[N][N];
    int gameOver;
    explicit MainWindow(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    Controller *myController;
    ~MainWindow();

    
private slots:
    void on_pbSetup_clicked();

    void on_pbStart_clicked();

    void on_cbHorizontal_clicked();

    void on_cbVertical_clicked();

    void on_sbShipSize_valueChanged(int arg1);


    void on_pb_Restart_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H




