//Matan Shtar - 324125350
//Niv Shteingart - 314830365

#pragma once
#include "Player.hpp"
#include <cstdlib>
#include <ctime>

class AiPlayer : public Player
{
    public:
    AiPlayer(const std::string name);
    void placeAllShips() override;
    void makeMove(Player* opponent) override;
    int getRandomCoordinate();
};