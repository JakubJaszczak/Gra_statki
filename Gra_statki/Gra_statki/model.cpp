#include "model.h"
#include <QDebug>
Model::Model()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            tab1[i][j].ship=false;
            tab2[i][j].ship=false;
            tab1[i][j].shot=false;
            tab2[i][j].shot=false;
            tab1[i][j].collision=false;
            tab2[i][j].collision=false;
        }
    }
    for(int i=0;i<10;i++)
    {
        tabShip1[i]=NULL;
        tabShip2[i]=NULL;
    }
}


bool Model::placeShip(int coordX, int coordY, int playerIndex, bool orient, int shipSize)
{
    if(orient==false)//orient-false-horizontal,true-vertical
    {
        bool canPlace=true;
        if(coordX+shipSize>=N+1)//checks if ship doesnt go off the board
            canPlace=false;
        for(int i=0;i<shipSize;i++)
        {
            if(playerIndex==1)
            {
                if( tab1[coordX+i][coordY].collision==true)
                    canPlace=false;
            }
            else
            {
                if( tab2[coordX+i][coordY].collision==true)
                    canPlace=false;
            }
        }
        if(canPlace)
        {   for(int i=0;i<10;i++)
            {
                if(playerIndex==1)
                {
                    if(tabShip1[i]==NULL)
                    {
                        tabShip1[i]=new ship;
                        tabShip1[i]->x=coordX;
                        tabShip1[i]->y=coordY;
                        tabShip1[i]->shipSize=shipSize;
                        tabShip1[i]->kierunek=orient;
                        tabShip1[i]->playerIndex=1;
                        tabShip1[i]->trafionyZatopiony=shipSize;
                        break;
                    }
                }
                if(playerIndex==2)
                {
                    if(tabShip2[i]==NULL)
                    {
                        tabShip2[i]=new ship;
                        tabShip2[i]->x=coordX;
                        tabShip2[i]->y=coordY;
                        tabShip2[i]->shipSize=shipSize;
                        tabShip2[i]->kierunek=orient;
                        tabShip2[i]->playerIndex=2;
                        tabShip2[i]->trafionyZatopiony=shipSize;
                        break;
                    }
                }
            }

            for(int i=coordX;i<coordX+shipSize;i++)
            {   if(playerIndex==1)
                    tab1[i][coordY].ship=true;
                else tab2[i][coordY].ship=true;
            }
            for(int i=coordX-1;i<coordX+shipSize+1;i++)
            {
                setCollision(i,coordY+1,playerIndex,true);
                setCollision(i,coordY-1,playerIndex,true);
                setCollision(i,coordY,playerIndex,true);
            }
            return true;
        }
    }
    if(orient==true)
    {
        bool canPlace=true;

        if(coordY+shipSize>=N+1)//checks if ship doesnt go off the board
            canPlace=false;

        for(int i=0;i<shipSize;i++)
        {
            if(playerIndex==1)
            {
                if( tab1[coordX][coordY+i].collision==true)
                    canPlace=false;
            }
            else
            {
                if( tab2[coordX][coordY+i].collision==true)
                    canPlace=false;
            }
        }
        if(canPlace)
        {
            for(int i=0;i<10;i++)
            {
                if(playerIndex==1)
                {
                    if(tabShip1[i]==NULL)//add ship to first empty cell of the array
                    {
                        tabShip1[i]=new ship;
                        tabShip1[i]->x=coordX;
                        tabShip1[i]->y=coordY;
                        tabShip1[i]->shipSize=shipSize;
                        tabShip1[i]->kierunek=orient;
                        tabShip1[i]->playerIndex=1;
                        tabShip1[i]->trafionyZatopiony=shipSize;
                        break;
                    }
                }
                if(playerIndex==2)
                {
                    if(tabShip2[i]==NULL)
                    {
                        tabShip2[i]=new ship;
                        tabShip2[i]->x=coordX;
                        tabShip2[i]->y=coordY;
                        tabShip2[i]->shipSize=shipSize;
                        tabShip2[i]->kierunek=orient;
                        tabShip2[i]->playerIndex=2;
                        tabShip2[i]->trafionyZatopiony=shipSize;
                        break;
                    }
                }
            }
            for(int i=coordY;i<coordY+shipSize;i++)
            {   if(playerIndex==1)
                    tab1[coordX][i].ship=true;
                else tab2[coordX][i].ship=true;
            }
            for(int i=coordY-1;i<coordY+shipSize+1;i++)
            {
                setCollision(coordX-1,i,playerIndex,true);
                setCollision(coordX+1,i,playerIndex,true);
                setCollision(coordX,i,playerIndex,true);
            }
            return true;
        }
    }
    return false;
}

void Model::setCollision(int coordX, int coordY, int playerIndex,bool value)
{
    if(coordX>=0 && coordX<N && coordY>=0 && coordY<N)
    {
        if(playerIndex==1)
        {
            tab1[coordX][coordY].collision=value;
        }
        else tab2[coordX][coordY].collision=value;
    }
}

void Model::setShot(int coordX, int coordY, int playerIndex, bool value)
{
    if(coordX>=0 && coordX<N && coordY>=0 && coordY<N)
    {
        if(playerIndex==1)
        {
            tab2[coordX][coordY].shot=value;
        }
        else tab1[coordX][coordY].shot=value;
    }
}
void Model::restart()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            tab1[i][j].ship=false;
            tab2[i][j].ship=false;
            tab1[i][j].shot=false;
            tab2[i][j].shot=false;
            tab1[i][j].collision=false;
            tab2[i][j].collision=false;
        }
    }
    for(int i=0;i<10;i++)
    {
        tabShip1[i]=NULL;
        tabShip2[i]=NULL;
    }
}

int Model::gameOver(int playerIndex)
{
    int gameOver1=0;
    int gameOver2=0;
    for(int i=0;i<10;i++)
    {
        gameOver1=gameOver1+tabShip2[i]->trafionyZatopiony;
        gameOver2=gameOver2+tabShip1[i]->trafionyZatopiony;
    }
    if(gameOver1==0)
    return 1;
    if(gameOver2==0)
        return 2;
    return 0;

}

void Model::trafionyZatopiony(int coordX, int coordY,int playerIndex)
{
    if(playerIndex==1)
    {
        for(int i=0;i<10;i++)
        {
            if(tabShip2[i]==NULL)
            {
                return;
            }
            if(tabShip2[i]->kierunek==true)//0-horizontal,1-vertical
            {
                for(int j=0;j<tabShip2[i]->shipSize;j++)
                {
                    if(tabShip2[i]->x==coordX && tabShip2[i]->y+j==coordY)//checks if coords of the shot belong to any ship
                    {
                        tabShip2[i]->trafionyZatopiony--;
                    }
                }
            }
            else
            {
                for(int j=0;j<tabShip2[i]->shipSize;j++)
                {
                    if(tabShip2[i]->x+j==coordX && tabShip2[i]->y==coordY)
                    {
                        tabShip2[i]->trafionyZatopiony--;
                    }
                }
            }
            if(tabShip2[i]->trafionyZatopiony==0)
            {
                if(tabShip2[i]->kierunek==true)//vertical
                {
                    for(int k=tabShip2[i]->y-1;k<tabShip2[i]->y+tabShip2[i]->shipSize+1;k++)
                    {
                        setShot(tabShip2[i]->x-1,k,playerIndex,true);
                        setShot(tabShip2[i]->x+1,k,playerIndex,true);
                        setShot(tabShip2[i]->x,k,playerIndex,true);
                    }
                }
                else//horizontal
                {
                    for(int k=tabShip2[i]->x-1;k<tabShip2[i]->x+tabShip2[i]->shipSize+1;k++)
                    {
                        setShot(k,tabShip2[i]->y+1,playerIndex,true);
                        setShot(k,tabShip2[i]->y-1,playerIndex,true);
                        setShot(k,tabShip2[i]->y,playerIndex,true);
                    }
                }
            }
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(tabShip1[i]==NULL)
            {
                return;
            }
            if(tabShip1[i]->kierunek==true)//0-horizontal,1-vertical
            {
                for(int j=0;j<tabShip1[i]->shipSize;j++)
                {
                    if(tabShip1[i]->x==coordX && tabShip1[i]->y+j==coordY)
                    {
                        tabShip1[i]->trafionyZatopiony--;
                    }
                }
            }
            else
            {
                for(int j=0;j<tabShip1[i]->shipSize;j++)
                {
                    if(tabShip1[i]->x+j==coordX && tabShip1[i]->y==coordY)
                    {
                        tabShip1[i]->trafionyZatopiony--;
                    }
                }
            }
            if(tabShip1[i]->trafionyZatopiony==0)
            {
                if(tabShip1[i]->kierunek==true)
                {
                    for(int k=tabShip1[i]->y-1;k<tabShip1[i]->y+tabShip1[i]->shipSize+1;k++)
                    {
                        setShot(tabShip1[i]->x-1,k,playerIndex,true);
                        setShot(tabShip1[i]->x+1,k,playerIndex,true);
                        setShot(tabShip1[i]->x,k,playerIndex,true);
                    }
                }
                else
                {
                    for(int k=tabShip1[i]->x-1;k<tabShip1[i]->x+tabShip1[i]->shipSize+1;k++)
                    {
                        setShot(k,tabShip1[i]->y+1,playerIndex,true);
                        setShot(k,tabShip1[i]->y-1,playerIndex,true);
                        setShot(k,tabShip1[i]->y,playerIndex,true);
                    }
                }
            }
        }
    }
}





