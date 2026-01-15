//Matan Shtar - 324125350
//Niv Shteingart - 314830365

#pragma once
#include "Ship.hpp"

class Carrier : public Ship
{
    public:
        Carrier();
};

class Battleship : public Ship
{
    public:
        Battleship();
};

class Cruiser : public Ship
{
    public:
        Cruiser();
};

class Submarine : public Ship
{
    public:
        Submarine();
};

class Destroyer : public Ship
{
    public:
        Destroyer();
};