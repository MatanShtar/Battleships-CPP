//Matan Shtar - 324125350
#pragma once
#include <iostream>

class Grid
{
public:
    enum class TileState : char{
        WATER = '~',
        SHIP = 'S',
        MISS = 'M',
        HIT = 'X'      
    };
private:
    TileState cells[10][10];
public:
    Grid(); 
    ~Grid();
    bool isTileOccupied(int row, int col) const;
    bool inBounds(int row, int col, int shipSize, bool horizontal) const;
    void placeShip(int row, int col, int shipSize, bool horizontal);
    void markHit(int row, int col);
    void markMiss(int row, int col);
    TileState getCell(int row, int col) const;
    void printGrid(bool showShips);
};

