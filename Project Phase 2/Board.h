// This header file contains the player class type and related functions
#ifndef BOARD_H
#define BOARD_H

// Program libraries
#include <iostream>
#include <string>
using namespace std;

// Player class
class Board {

public:

	// Class constructor
	Board();

	// Class destructor
	~Board();

	// Board functions
	void Board::printBoard();
	void PositionCheck();
	void Remove();


private:

    // Variables for Board
    bool white;
    bool black;

	
};

#endif
