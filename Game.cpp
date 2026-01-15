// Matan Shtar - 324125350
//Niv Shteingart - 314830365

#include "Game.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Game::Game(Player *p1, Player *p2)
{
    this->player1 = p1;
    this->player2 = p2;
}

Game::~Game()
{
    delete player1;
    delete player2;
}

void Game::setup()
{
    cout << "--- Game Setup ---" << endl;
    player1->placeAllShips();
    cout << endl;

    player2->placeAllShips();
    cout << endl;

    cout << "All ships deployed! Battle starting..." << endl << endl;
}

void Game::start()
{
    while (!isGameOver())
    {
        cout << "========================================" << endl;
        player1->makeMove(player2);
        if (player2->allShipsSunk())
        {
            cout << R"(
       ___________
      '._==_==_=_.'
      .-\:      /-.
     | (|:.     |) |
      '-|:.     |-'     VICTORY!
        \::.    /      PLAYER 1 WINS
         '::. .'
           ) (
         _.' '._
    )" << endl;
            break;
        }
        cout << endl;

        player2->makeMove(player1);

        if (player1->allShipsSunk())
        {
            cout << R"(
       ___________
      '._==_==_=_.'
      .-\:      /-.
     | (|:.     |) |
      '-|:.     |-'     VICTORY!
        \::.    /      PLAYER 2 WINS
         '::. .'
           ) (
         _.' '._
    )" << endl;
            break;
        }
 
        player1->displayMyGrid();
        player1->displayFleetStatus();

        player1->displayEnemyGrid(player2);
        player2->displayFleetStatus();

    }
}

bool Game::isGameOver()
{
    if (player1->allShipsSunk() || player2->allShipsSunk())
        return true;
    return false;
}