// This header file contains the Player class type and related functions
#ifndef PLAYER_H
#define PLAYER_H

// Program libraries
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string>
using namespace std;

// Player class
class Player {
public:

	// Class constructor
	Player();
	Player(std::string ids);

	// Class destructor
	~Player();

	// Player functions
	void userInput();
	void playerTurn();
	bool playerWin();
	std::string playerID();
	void createPieces(bool playerOrder);
	int charToInt(char columnChar);

private:

    // Variables for player
    bool turn;
    bool win;
	std::string id;
};

#endif