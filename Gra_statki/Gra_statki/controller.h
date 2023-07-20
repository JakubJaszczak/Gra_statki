#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "model.h"
#include<QMouseEvent>
#include "mainwindow.h"
#include <QDebug>

class MainWindow;
class Controller
{
public:
    Controller();
    bool mode;//0-setup,1-shooting phase
    bool orient;//orientation of the ship during setup-0-horizontal,1-vertical
    int coordX,coordY;// X and Y array coord(transformed from pixels)
    int shipSize;
    int playerIndex;
    int counter[4];//counter of ships left to set up
    Model* myModel;
    MainWindow* myWindow;
    void click(int x, int y, int width, int height);
    void playerSetupSwitch();// checks if player has any ships left to set up;if no switches playerIndex,resets counter[];if player2 has no more ships turns on shooting phase;
    void restart();// resets all the data maintained in controller
};

#endif // CONTROLLER_H
