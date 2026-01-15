//Matan Shtar - 324125350
//Niv Shteingart - 314830365

#include "Ship.hpp"
using namespace std;

Ship::Ship(const string shipName, int shipSize)
{
    this->name = shipName;
    this->size = shipSize;
    this->hitsTaken = 0;
}

Ship::~Ship(){}

void Ship::takeHit()
{
    this->hitsTaken++;
    std::cout << this->name << " Got Hit!" << std::endl;
}

bool Ship::isSunk() const
{
    if (this->hitsTaken >= this->size)
        return true;
    return false;
}

void Ship::setLocation(int row, int col, bool horizontal)
{
    this->row = row;
    this->col = col;
    this->horizontal = horizontal;
}

bool Ship::shipCoverage(int row, int col)const
{
    if(this->horizontal)
    {
        return (this->row == row) && (col >= this->col && col < this->col + this->size);
    }
    else
    {
        return (this->col == col) && (row >= this->row && row < this->row + this->size);
    }
}

string Ship::getName() {return this->name;}
int Ship::getSize() {return this->size;}
int Ship::getHitsTaken() const { return this->hitsTaken;}