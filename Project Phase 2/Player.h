// This header file contains the Player class type and related functions
#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.h";
//#include "Board.h";

// Program libraries
#include <iostream>
#include <string>
using namespace std;

// Player class
class Player {
public:

	// Class constructor
	Player();
	Player(string ids);

	// Class destructor
	~Player();

	// Player functions
	void userInput();
	void playerTurn();
	bool playerWin();
	string playerID();
	void createPieces(bool playerOrder);

private:

    // Variables for player
    bool turn;
    bool win;
	string id;
};

#endif