//Matan Shtar - 324125350
//Niv Shteingart - 314830365

#pragma once
#include <iostream>
#include "Ship.hpp"
#include "Grid.hpp"

const int NUM_OF_SHIPS = 5;

class Player
{
protected:
    std::string playerName;
    Ship* ships[5];
    Grid grid;
    bool validateShipPlacement(int row, int col, int shipSize, bool horizontal);
    void processShot(Player* opponent, int row, int col);
public:
    Player(const std::string name);
    virtual ~Player();
    virtual void placeAllShips() = 0;
    virtual void makeMove(Player* opponent) = 0;
    bool allShipsSunk() const;
    void displayMyGrid();
    void displayEnemyGrid(Player* opponent);
    Grid* getGrid();
    Ship* getShip(int i);
    std::string getName() const;
    void displayFleetStatus();
    
};