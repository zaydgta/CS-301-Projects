// This header file contains the player class type and related functions
#ifndef PLAYER_H
#define PLAYER_H

// Program libraries
#include <iostream>
#include <string>
using namespace std;

// Player class
class Player {

public:

	// Class constructor
	Player();

	// Class destructor
	~Player();

	// Player functions
	void userInput();
	void playerTurn();
	bool playerWin();

private:

    // Variables for player
    bool turn;
    bool win;
	
};

#endif
