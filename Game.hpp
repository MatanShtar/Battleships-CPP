//Matan Shtar - 324125350
//Niv Shteingart - 314830365

#include "Player.hpp"
#pragma once
class Game
{
private:
    Player* player1;
    Player* player2;
public:
    Game(Player* p1, Player* p2);
    ~Game();
    void setup();
    void start();
    bool isGameOver();
};

