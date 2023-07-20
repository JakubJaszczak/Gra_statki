#include "controller.h"
#include <QDebug>

Controller::Controller()
{   playerIndex=1;
    mode=false;
    shipSize=1;
    orient=false;
    for(int i=0;i<4;i++)
    {counter[i]=i+1;}
}

void Controller::click(int x, int y,int width,int height)
{
    switch(mode)//setting up ships
    {case false:
        if(playerIndex==1)//check if clicked on board_1
        {
            if(x<width/27 || x>width*11/27 || y<(height-width*10/27)/2 || y>height-(height-10*width/27)/2)
                return;
        }
        if(playerIndex==2)//check if clicked on board_2
        {
            if(x<width*13/27 || x>width*23/27 || y<(height-width*10/27)/2 || y>height-(height-10*width/27)/2)
                return;
        }

        if(playerIndex==1)//transforming pixels to array index
        {
            coordX=(x-width/27)/(width/27);
            coordY=(y-(height-width*10/27)/2)/(width/27);
        }
        if(playerIndex==2)//transforming pixels to array index
        {
            coordX=(x-width*13/27)/(width/27);
            coordY=(y-(height-width*10/27)/2)/(width/27);
        }

        if(counter[4-shipSize]>0)//if player has any ships left and conditions from placeShip() are fullfiled place a ship there and decrease value of counter;
        {
            if(myModel->placeShip(coordX,coordY,playerIndex,orient,shipSize))
            {
                counter[4-shipSize]--;
            }
        }
        for(int i=0;i<N;i++)// pass the data to mainWindow
        {
            for(int j=0;j<N;j++)
            {
                if(myModel->tab1[i][j].ship==true)
                    myWindow->tab1[i][j]=1;
                if(myModel->tab1[i][j].ship==false)
                    myWindow->tab1[i][j]=0;
                if(myModel->tab2[i][j].ship==true)
                    myWindow->tab2[i][j]=1;
                if(myModel->tab2[i][j].ship==false)
                    myWindow->tab2[i][j]=0;
            }
        }
        playerSetupSwitch();

        break;
    case true://shooting phase
        if(myModel->gameOver(playerIndex)!=0)
        {
            return;
        }
        if(playerIndex==2)//check if clicked on board_1
        {
            if(x<width/27 || x>width*11/27 || y<(height-width*10/27)/2 || y>height-(height-10*width/27)/2)
                return;
        }
        if(playerIndex==1)//check if clicked on board_2
        {
            if(x<width*13/27 || x>width*23/27 || y<(height-width*10/27)/2 || y>height-(height-10*width/27)/2)
                return;
        }

        if(playerIndex==2)
        {
            coordX=(x-width/27)/(width/27);
            coordY=(y-(height-width*10/27)/2)/(width/27);
        }
        if(playerIndex==1)
        {
            coordX=(x-width*13/27)/(width/27);
            coordY=(y-(height-width*10/27)/2)/(width/27);
        }

        switch(playerIndex)
        {case 1:
            if(myModel->tab2[coordX][coordY].shot==true)// return if player has shot in a certain posision before
            {
                return;
            }
            if(myModel->tab2[coordX][coordY].ship==true)//if there is a ship on given coordinates
            {
                //myWindow->tab2[coordX][coordY]=2;//pass the data to mainWindow
               // myModel->tab2[coordX][coordY].ship=false;//change th data in model
                myModel->trafionyZatopiony(coordX,coordY,playerIndex);
            }
            else
            {
                playerIndex=2;

               // myWindow->tab2[coordX][coordY]=3;
            }
            myModel->tab2[coordX][coordY].shot=true;
            break;
        case 2:
            if(myModel->tab1[coordX][coordY].shot==true)
            {
                return;
            }
            if(myModel->tab1[coordX][coordY].ship==true)
            {
                //myWindow->tab1[coordX][coordY]=2;
                //myModel->tab1[coordX][coordY].ship=false;
                myModel->trafionyZatopiony(coordX,coordY,playerIndex);
            }
            else
            {
                playerIndex=1;
               // myWindow->tab1[coordX][coordY]=3;
            }
            myModel->tab1[coordX][coordY].shot=true;
            break;
        }//switch playerIndex
        if(myModel->gameOver(playerIndex)==1)
        {
            myWindow->gameOver=1;
        }
        if(myModel->gameOver(playerIndex)==2)
        {
            myWindow->gameOver=2;
        }
        break;
    }//switch mode
    for(int i=0;i<N;i++)// pass the data to mainWindow
    {
        for(int j=0;j<N;j++)
        {
            if(myModel->tab1[i][j].ship==true && myModel->tab1[i][j].shot==true)
                myWindow->tab1[i][j]=2;
            if(myModel->tab1[i][j].ship==false && myModel->tab1[i][j].shot==true)
                myWindow->tab1[i][j]=3;
            if(myModel->tab2[i][j].ship==true && myModel->tab2[i][j].shot==true)
                myWindow->tab2[i][j]=2;
            if(myModel->tab2[i][j].ship==false && myModel->tab2[i][j].shot==true)
                myWindow->tab2[i][j]=3;
        }
    }
    myWindow->update();//repaint
}
void Controller::playerSetupSwitch()
{
    int sum=0;
    for(int i=0;i<4;i++)
    {sum=sum+counter[i];}
    if(sum==0)
    {
        if(playerIndex==1)
        {
            playerIndex=2;
            for(int i=0;i<4;i++)
            {counter[i]=i+1;}
        }
        else
        {
            mode=true;
            playerIndex=1;
        }
    }
}

void Controller::restart()
{     playerIndex=1;
      mode=false;
        shipSize=1;
          orient=false;
            for(int i=0;i<4;i++)
            {counter[i]=i+1;}
              myModel->restart();

}
