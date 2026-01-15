// Matan Shtar - 324125350
//Niv Shteingart - 314830365

#include "AiPlayer.hpp"
using namespace std;

AiPlayer::AiPlayer(const string name) : Player(name) {}

void AiPlayer::placeAllShips()
{
    int row, col;
    bool horizontal;
    cout << "AI is deploying ships..." << endl;
    for (int i = 0; i < NUM_OF_SHIPS; i++)
    {
        while (true)
        {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
            horizontal = (rand() % 2) == 0;
            if(validateShipPlacement(row, col, ships[i]->getSize(), horizontal))
            {
                grid.placeShip(row,col,ships[i]->getSize(),horizontal);
                ships[i]->setLocation(row,col,horizontal);
                break;
            }
        }
    }
    cout << "AI Has finished deploying ships" << endl;
}
void AiPlayer::makeMove(Player *opponent)
{
    int row,col;
    do
    {
        row = getRandomCoordinate();
        col = getRandomCoordinate();

    }while(opponent->getGrid()->getCell(row,col) == Grid::TileState::HIT ||
           opponent->getGrid()->getCell(row,col) == Grid::TileState::MISS);
    cout << "AI Attacks " << row << " " << col << endl;
    processShot(opponent,row,col);
}

int AiPlayer::getRandomCoordinate() { return rand() % 10; }