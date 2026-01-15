//Matan Shtar - 324125350
//Niv Shteingart - 314830365

#include "Grid.hpp"
using namespace std;

Grid::Grid()
{
    int col = 10, row = 10;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            this->cells[i][j] = TileState::WATER;
        }
    }
}

Grid::~Grid(){}

bool Grid::isTileOccupied(int row, int col) const
{
    return this->cells[row][col] == TileState::SHIP || this->cells[row][col] == TileState::HIT;
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
    if(horizontal)
    {
        return row >= 0 && row < 10 && col >= 0 && (col+shipSize) <= 10;
    }
    else
    {
        return col >= 0 && col < 10 && row >= 0 && (row+shipSize) <= 10;
    }
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal)
{
    if(!inBounds(row,col,shipSize,horizontal))
    {
        cout << "Cannot Place Ship Here!" << endl;
        return;
    }

    if(horizontal)
    {
        for(int i = 0; i<shipSize; i++)
            this->cells[row][col+i] = TileState::SHIP;
    }
    else
        for(int i = 0; i<shipSize; i++)
            this->cells[row+i][col] = TileState::SHIP;
}

Grid::TileState Grid::getCell(int row, int col) const
{
    return this->cells[row][col];
}

void Grid::markHit(int row, int col)
{
    if(this->cells[row][col] == TileState::SHIP)
    {
        this->cells[row][col] = TileState::HIT;
        cout << "Hit!" << endl;
    }
    else
        cout << "Error: No Ship Here." << endl;
}

void Grid::markMiss(int row, int col)
{
    if(this->cells[row][col] == TileState::WATER)
    {
        this->cells[row][col] = TileState::MISS;
        cout << "Miss!" << endl;
    }
    else
        cout << "Error: There a ship here." << endl;
}

void Grid::printGrid(bool showShips)
{
    const string ICON_WATER = "[~]"; 
    const string ICON_HIT   = "[X]"; 
    const string ICON_MISS  = "[M]"; 
    const string ICON_SHIP  = "[S]";
    cout << "   0   1   2   3   4   5   6   7   8   9" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << i << " ";
        for(int j = 0; j < 10; j++)
        {
            TileState cell = this->cells[i][j];

           
            if (cell == TileState::HIT)
            {
                cout << ICON_HIT << " ";
            }
            else if (cell == TileState::MISS)
            {
                cout << ICON_MISS << " ";
            }
            else if (cell == TileState::SHIP)
            {
                if (showShips) cout << ICON_SHIP << " ";
                else           cout << ICON_WATER << " "; 
            }
            else
            {
                cout << ICON_WATER << " ";
            }
        }
        std::cout << std::endl;
    }
}