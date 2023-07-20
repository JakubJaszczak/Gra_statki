#ifndef MODEL_H
#define MODEL_H
struct field//structure which holds data of every field
{
    bool shot;//if there was a shot on certain field on the board
    bool ship;      // if there is a ship
    bool collision;//false-can put a ship there,true-cant
};
struct ship//data of player's ships
{
    int x;//x coordinate of the ship
    int y;//y coordinate of the ship
    int shipSize;//size of the ship
    int playerIndex;//player that the ship belons to
    bool kierunek;//0-horizontal,1-vertical
    int trafionyZatopiony;//amount of ship elements left
};
const int N=10;// array size
class Model
{
public:
    Model();
    field tab1[N][N];
    field tab2[N][N];
    ship *tabShip1[10];
    ship *tabShip2[10];
    bool placeShip(int coordX,int coordY,int playerIndex,bool orient,int shipSize);//check if u can place a ship in a certain position(if yes returns true, if no-false)
    void setCollision(int coordX,int coordY,int playerIndex,bool value);
    void setShot(int coordX,int coordY,int playerIndex,bool value);
    void trafionyZatopiony(int coordX, int coordY, int playerIndex);
    void restart();//resets all the data maintained in model;
    int gameOver(int playerIndex);//if returns 1-player_1 won;if 2-player_2 won;if 0-game continues;
private:
};



#endif // MODEL_H
