//Matan Shtar - 324125350
//Niv Shteingart - 314830365

#include "Player.hpp"
#include "ShipClasses.hpp"
#include <iomanip>
using namespace std;

Player::Player(const string name) : playerName(name)
{
    this->ships[0] = new Destroyer();
    this->ships[1] = new Submarine();
    this->ships[2] = new Cruiser();
    this->ships[3] = new Battleship();
    this->ships[4] = new Carrier();
}

Player::~Player()
{
    for(int i = 0; i < NUM_OF_SHIPS; i++)
    {
        if(this->ships[i] != nullptr)
        {
            delete this->ships[i];
            this->ships[i] = nullptr;
        }
    }
}

bool Player::allShipsSunk() const
{
    for(int i = 0; i<NUM_OF_SHIPS; i++)
    {
        if(ships[i]->isSunk() == false)
            return false;
    }
    return true;
}

void Player::displayMyGrid()
{
    cout << endl << "--- " << this->playerName << "'s Board ---" << endl;
    this->grid.printGrid(true);
}

void Player::displayEnemyGrid(Player* opponent)
{
    cout << endl << "--- " << opponent->getName() << "'s Board ---" << endl;
    opponent->grid.printGrid(false);
}

Grid* Player::getGrid(){return &grid;};
Ship* Player::getShip(int i) {
    if (i >= 0 && i < NUM_OF_SHIPS) return ships[i];
    return nullptr;
}

string Player::getName()const {return playerName;}

bool Player::validateShipPlacement(int row, int col, int shipSize, bool horizontal)
{
    if (!grid.inBounds(row, col, shipSize, horizontal))
    {
        return false;
    }

    for (int j = 0; j < shipSize; j++)
    {
        int r = row + (horizontal ? 0 : j);
        int c = col + (horizontal ? j : 0);
        
        if (grid.isTileOccupied(r, c))
        {
            return false; 
        }
    }
    return true;
}

void Player::processShot(Player* opponent, int row, int col)
{
    Grid::TileState targetState = opponent->getGrid()->getCell(row,col);
    switch(targetState)
    {
    case Grid::TileState::WATER:
        opponent->getGrid()->markMiss(row,col);
        break;
    case Grid::TileState::HIT:
    case Grid::TileState::MISS:
        cout <<"You already attacked here! Turn wasted." << endl;
        break;
    case Grid::TileState::SHIP:
        opponent->getGrid()->markHit(row,col);
        for(int i = 0; i < NUM_OF_SHIPS; i++)
        {
            if(opponent->getShip(i)->shipCoverage(row,col))
            {
                opponent->getShip(i)->takeHit();
                if(opponent->getShip(i)->isSunk())
                {
                    cout << this->getName() <<" sunk the enemy's " << opponent->getShip(i)->getName() << "!" << endl;
                }
                break;
            }
        }
        break;

    default:
        cout << "Error: Unknown tile state" << endl;

    }
}

void Player::displayFleetStatus()
{
    cout << "--- " << playerName << "'s Fleet ---" << endl;

    for (int i = 0; i < NUM_OF_SHIPS; i++)
    {
        Ship* s = ships[i];
        int maxHP = s->getSize();
        int taken = s->getHitsTaken();
        int currentHP = maxHP - taken;

        cout << left << setw(12) << s->getName();

        cout << "[";
        for(int k=0; k < currentHP; k++) cout << "#";
        for(int k=0; k < taken; k++)     cout << "_";
        cout << "] ";

        string hpText = to_string(currentHP) + "/" + to_string(maxHP) + " HP";
        cout << left << setw(9) << hpText;

        if (s->isSunk()) cout << "DEAD ";
        else             cout << "     ";
        if (i == 2) 
            cout << "\n"; 
        else if (i < 4) 
            cout << "| ";
    }
    cout << endl;
}