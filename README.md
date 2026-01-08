# 🚢 Battleship C++

> A robust, object-oriented implementation of the classic strategy game Battleship, built entirely in C++.

![Language](https://img.shields.io/badge/Language-C++11-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20Mac-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

## 📖 Overview

This project is a console-based simulation of the naval combat game **Battleship**. It features a turn-based system where a **Human Player** competes against an **AI Opponent**. The project was designed with a focus on **Object-Oriented Programming (OOP)** principles, specifically leveraging polymorphism, inheritance, and dynamic memory management.

The game features a rich ASCII interface with real-time fleet health tracking, input validation, and an "intelligent" AI that hunts for ships without repeating moves.

---

## ✨ Key Features

* **🧠 Smart AI Opponent:** The AI randomizes attacks but remembers previous moves to avoid hitting the same tile twice.
* **🛡️ Robust Input Validation:** Prevents crashes by handling out-of-bounds coordinates, and overlapping ship placements.
* **📊 Dynamic Fleet Status:** A real-time "Health Bar" display for every ship, showing remaining hit points and sunk status.
* **🎨 Clean ASCII UI:** Features a high-visibility grid with distinct symbols for Hits `[X]`, Misses `[M]`, Ships `[S]`, and Water `[~]`.

---

## 🎮 How to Play

1.  **Deployment Phase:**
    * You will be prompted to place 5 ships: **Carrier (5)**, **Battleship (4)**, **Cruiser (3)**, **Submarine (3)**, and **Destroyer (2)**.
    * Enter coordinates (Row 0-9, Column 0-9) and orientation (H for Horizontal, V for Vertical).
2.  **Battle Phase:**
    * Enter target coordinates to fire at the enemy grid.
    * The game provides immediate feedback: **Hit**, **Miss**, or **Sunk**.
3.  **Victory:**
    * The first player to sink the entire enemy fleet wins the game!

---

## 🛠️ Installation & Compilation

You can compile this project using any standard C++ compiler (like `g++`).

### 1. Clone the Repository
git clone [https://github.com/MatanShtar/Battleships-CPP.git](https://github.com/MatanShtar/Battleships-CPP.git)
cd Battleships-CPP

### 2. Compile
Run the following command in your terminal to link all source files:

    g++ main.cpp Game.cpp Player.cpp HumanPlayer.cpp AiPlayer.cpp Grid.cpp Ship.cpp ShipClasses.cpp -o battleship
   
### 4. Run
#### Windows:

    battleship.exe
#### Mac/Linux:

    ./battleship
## 🏗️ Technical Architecture
This project uses a modular class hierarchy to separate logic, state, and user interaction.

Class Diagram Overview
1.  **Game:** The central controller. Manages the game loop, turns, and win conditions.

2.  **Grid:** Represents the 10x10 board. Handles logic for collisions, boundaries, and cell states (WATER, SHIP, HIT, MISS).

3.  **Player (Abstract Base Class):**

      * Defines the interface for placeAllShips() and makeMove().

      * Manages the Grid and the array of Ship* pointers.

      * HumanPlayer: Implements logic for user input via std::cin.

      * AiPlayer: Implements logic for randomized, valid computer moves.

4.  **Ship** (Base Class):

      * Tracks health, size, and location.

      * Derived Classes: Carrier, Battleship, Cruiser, Submarine, Destroyer (each with specific sizes).

### Code Snippet: Polymorphism
The game loop treats both Human and AI generically using the base Player pointer:

    // Inside Game::start()
    // The game doesn't need to know IF it is a Human or AI, just that it is a Player.
    player1->makeMove(player2); 
    if (player2->allShipsSunk()) { /* Win Logic */ }
    
    player2->makeMove(player1);
    if (player1->allShipsSunk()) { /* Win Logic */ }
## 📸 Screenshots (ASCII)
The Board View:

    --- Human's Turn ---

    --- Enemy Fleet Status ---
    Destroyer   [##] 2/2 HP     |  Submarine   [###] 3/3 HP
    Battleship  [    ] 0/4 DEAD |  Carrier     [#####] 5/5 HP    

    --- Opponent's Board ---
       0   1   2   3   4   5   6   7   8   9
    0 [~] [M] [~] [~] [~] [~] [~] [~] [~] [~]
    1 [~] [~] [X] [X] [X] [X] [~] [~] [~] [~]
    ...
## 👤 Author
#### Matan Shtar

### My Links:

**[GitHub](https://github.com/MatanShtar)**

**[LinkedIn](https://www.linkedin.com/in/matan-shtar-8114173a4/)**


## 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
