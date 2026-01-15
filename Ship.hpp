//Matan Shtar - 324125350
//Niv Shteingart - 314830365

#pragma once
#include <iostream>
#include <string>

class Ship
{
private:
    std::string name;
    int size;
    int hitsTaken;
    int row;
    int col;
    bool horizontal;

public:
    Ship(const std::string shipName, int shipSize);
    virtual ~Ship();
    virtual void takeHit();
    bool isSunk() const;
    void setLocation(int row, int col, bool horizontal);
    bool shipCoverage(int row, int col) const;
    std::string getName();
    int getSize();
    int getHitsTaken() const;
};
