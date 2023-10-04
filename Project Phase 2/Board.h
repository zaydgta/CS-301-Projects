// This header file contains the Board class type and related functions
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
	void printBoard();
	void positionCheck();
	void remove();

private:

    // Variables for Board
	char board[9][9];
    bool white;
    bool black;
};

#endif
