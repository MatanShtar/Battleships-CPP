//Matan Shtar - 324125350
//Niv Shteingart - 314830365

#include "HumanPlayer.hpp"
#include <iostream>
using namespace std;

HumanPlayer::HumanPlayer(const string name) : Player(name){}

void HumanPlayer::placeAllShips()
{
    int rowPlacement, colPlacement;
    char orientation;
    bool horizontalPlacement;
    for(int i = 0; i < NUM_OF_SHIPS; i++)
    {
        cout << "Deploying " << ships[i]->getName() << " (Size: " << ships[i]->getSize() << ")" <<endl;
        cout << "Enter Coordinates (Row Column) and Orientation (H/V)";
        cin >> rowPlacement >> colPlacement >> orientation;
        horizontalPlacement = (orientation == 'H' || orientation == 'h');

        if(!(validateShipPlacement(rowPlacement,colPlacement,ships[i]->getSize(),horizontalPlacement)))
        {
            cout << "Cannot place ship here, try again." << endl;
            i--;
            continue;
        }

        grid.placeShip(rowPlacement, colPlacement, ships[i]->getSize(), horizontalPlacement);
        ships[i]->setLocation(rowPlacement,colPlacement,horizontalPlacement);
        displayMyGrid();
    }
}

void HumanPlayer::makeMove(Player* opponent)
{
    int row,col;
    while(true)
    {
        cout << "Enter where you want to strike (X Y) ";
        cin >> row >> col;
        if (row >= 0 && row < 10 && col >= 0 && col < 10)
            {
                break; 
            }
        cout << "Invalid coordinates! Please enter numbers between 0 and 9." << endl;
    }
    processShot(opponent,row,col);
    // displayMyGrid(); 
    // displayEnemyGrid(opponent);
}

