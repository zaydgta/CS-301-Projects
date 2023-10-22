// This header file contains the Player class type and related functions
#ifndef PLAYER_H
#define PLAYER_H

// Program libraries
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <vector>
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
	int charToInt(char columnChar);

private:

    // Variables for player
    bool turn;
    bool win;
	string id;
	vector<Piece> playerPieces;
};

#endif