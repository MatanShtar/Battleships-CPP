//Matan Shtar - 324125350
#pragma once
#include "Player.hpp"

class HumanPlayer : public Player
{
    public:
    HumanPlayer(const std::string name);
    void placeAllShips() override;
    void makeMove(Player* opponent) override;
};