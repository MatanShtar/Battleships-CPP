//Matan Shtar - 324125350
#include "ShipClasses.hpp"
using namespace std;

Carrier::Carrier() : Ship("Carrier", 5){}
Battleship::Battleship() : Ship("Battleship", 4){}
Cruiser::Cruiser() : Ship("Cruiser", 3){}
Submarine::Submarine() : Ship("Submarine", 3){}
Destroyer::Destroyer() : Ship("Destroyer", 2){}