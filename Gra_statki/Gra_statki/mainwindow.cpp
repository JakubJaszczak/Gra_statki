#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            tab1[i][j]=0;
            tab2[i][j]=0;
        }
    }
    ui->lb_gameState->setText("Gracz 1 rozstawia statki");
    gameOver=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    myController->click(event->x(),event->y(),width(),height());
    if(myController->mode==false && myController->playerIndex==1)
        ui->lb_gameState->setText("Gracz 1 rozstawia statki");
    if(myController->mode==false && myController->playerIndex==2)
        ui->lb_gameState->setText("Gracz 2 rozstawia statki");
    if(myController->mode==true && myController->playerIndex==1)
        ui->lb_gameState->setText("Gracz 1 strzela");
    if(myController->mode==true && myController->playerIndex==2)
        ui->lb_gameState->setText("Gracz 2 strzela");
    if(gameOver==1)
        ui->lb_gameState->setText("Gracz 1 wygrał");
    if(gameOver==2)
        ui->lb_gameState->setText("Gracz 2 wygrał");
    switch(myController->shipSize)//automatically change value of spinBox
    {
    case 4:
        if(myController->counter[4-myController->shipSize]==0)
        {
            ui->sbShipSize->setValue(1);
        }
        break;
    default:
        if(myController->counter[4-myController->shipSize]==0)
        {
            ui->sbShipSize->setValue(myController->shipSize+1);
        }
        break;
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter qpainter(this);
        for(int i=0;i<N+1;i++)//drowing board
        {
            qpainter.drawLine(width()/27+width()*i/27,(height()-width()*10/27)/2,width()/27+width()*i/27,height()-(height()-10*width()/27)/2);
        }
        for(int i=0;i<N+1;i++)
        {
            qpainter.drawLine(width()/27,((height()-10*width()/27)/2)+width()*i/27,width()*11/27,((height()-10*width()/27)/2)+width()*i/27);
        }

        for(int i=0;i<N+1;i++)
        {
            qpainter.drawLine(width()*13/27+width()*i/27,(height()-width()*10/27)/2,width()*13/27+width()*i/27,height()-(height()-10*width()/27)/2);
        }
        for(int i=0;i<N+1;i++)
        {
            qpainter.drawLine(width()*13/27,((height()-10*width()/27)/2)+width()*i/27,width()*23/27,((height()-10*width()/27)/2)+width()*i/27);
        }
        for(int i=0;i<N;i++)//cou
        {
            for(int j=0;j<N;j++)
            {if(tab1[i][j]==0)
                    qpainter.fillRect((width()/27+width()/27*i)+1,(((height()-width()*10/27)/2)+width()/27*j)+1,width()/27-1,width()/27-1,Qt::blue);
                else if(tab1[i][j]==1)
                    qpainter.fillRect((width()/27+width()*i/27)+1,(((height()-width()*10/27)/2)+width()/27*j)+1,width()/27-1,width()/27-1,myController->playerIndex==1?Qt::black:Qt::blue);
                else if(tab1[i][j]==2)
                    qpainter.fillRect((width()/27+width()*i/27)+1,(((height()-width()*10/27)/2)+width()/27*j)+1,width()/27-1,width()/27-1,Qt::red);
                else if(tab1[i][j]==3)
                    qpainter.fillRect((width()/27+width()*i/27)+1,(((height()-width()*10/27)/2)+width()/27*j)+1,width()/27-1,width()/27-1,Qt::green);
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {if(tab2[i][j]==0)
                    qpainter.fillRect((width()*13/27+width()*i/27)+1,(((height()-width()*10/27)/2)+width()/27*j)+1,width()/27-1,width()/27-1,Qt::blue);
                else if(tab2[i][j]==1)
                    qpainter.fillRect((width()*13/27+width()*i/27)+1,(((height()-width()*10/27)/2)+width()/27*j)+1,width()/27-1,width()/27-1,myController->playerIndex==2?Qt::black:Qt::blue);
                else if(tab2[i][j]==2)
                    qpainter.fillRect((width()*13/27+width()*i/27)+1,(((height()-width()*10/27)/2)+width()/27*j)+1,width()/27-1,width()/27-1,Qt::red);
                else if(tab2[i][j]==3)
                    qpainter.fillRect((width()*13/27+width()*i/27)+1,(((height()-width()*10/27)/2)+width()/27*j)+1,width()/27-1,width()/27-1,Qt::green);
            }
        }


};

void MainWindow::on_pbSetup_clicked()
{
    myController->mode=false;
}

void MainWindow::on_pbStart_clicked()
{
    myController->mode=true;
}

void MainWindow::on_cbHorizontal_clicked()
{
    myController->orient=false;
}

void MainWindow::on_cbVertical_clicked()
{
    myController->orient=true;
}

void MainWindow::on_sbShipSize_valueChanged(int arg1)
{       myController->shipSize=arg1;
}

void MainWindow::on_pb_Restart_clicked()
{
    myController->restart();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            tab1[i][j]=0;
            tab2[i][j]=0;
        }
    }
    ui->lb_gameState->setText("Gracz 1 rozstawia statki");
    gameOver=0;
    ui->cbHorizontal->setChecked(true);
    ui->sbShipSize->setValue(1);
    update();
}
