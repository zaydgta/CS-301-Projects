// This header file contains the Board class type and related functions
#ifndef BOARD_H
#define BOARD_H

// Program libraries
#include <iostream>
#include <string>
using namespace std;

const int ROW = 9;
const int COL = 9;

// Player class
class Board {
public:

	// Class constructor
	Board();

	// Class destructor
	~Board();

	// Board functions
	void testingBoard(); //NOT NEEDED, JUST FOR DEBUGGING
	void printBoard();
	void positionCheck();
	void removePiece();

private:

    // Variables for Board
	char board[ROW][COL] = { '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                             '1', '0', '0', '0', '0', '0', '0', '0', '0',
                             '2', '0', '0', '0', '0', '0', '0', '0', '0',
                             '3', '0', '0', '0', '0', '0', '0', '0', '0',
                             '4', '0', '0', '0', '0', '0', '0', '0', '0',
                             '5', '0', '0', '0', '0', '0', '0', '0', '0',
                             '6', '0', '0', '0', '0', '0', '0', '0', '0',
                             '7', '0', '0', '0', '0', '0', '0', '0', '0',
                             '8', '0', '0', '0', '0', '0', '0', '0', '0' };
    bool white;
    bool black;
};

#endif
