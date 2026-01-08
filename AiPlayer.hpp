//Matan Shtar - 324125350
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