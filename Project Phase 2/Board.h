// This header file contains the Board class type and related functions
#ifndef BOARD_H
#define BOARD_H

// Program libraries
#include "Player.h"
#include "Piece.h"
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
	void removePiece(int r, int c);
	
	//A struct that holds all the information of a space on the board 
    struct checkerSpace { 
        int row;
        int column;
        char value; //this is displayed on the board
        bool player; //which player's piece is on the space
        bool status; //taken = 1 or empty = 0
        bool nullSpace; //grey spaces (nonplay zones)
    };

private:
    // Variables for Board

	checkerSpace board[ROW][COL] = { {{0, 0, '0', NULL, NULL, 1}, {0, 1, 'A', NULL, NULL,    1}, {0, 2, 'B', NULL, NULL,    1}, {0, 3, 'C', NULL, NULL,    1}, {0, 4, 'D', NULL, NULL,    1}, {0, 5, 'E', NULL, NULL,    1}, {0, 6, 'F', NULL, NULL,    1}, {0, 7, 'G', NULL, NULL,    1}, {0, 8, 'H', NULL, NULL,    1}},
	                                 {{1, 0, '1', NULL, NULL, 1}, {1, 1, '0', NULL, NULL, NULL}, {1, 2, '0', NULL, NULL, NULL}, {1, 3, '0', NULL, NULL, NULL}, {1, 4, '0', NULL, NULL, NULL}, {1, 5, '0', NULL, NULL, NULL}, {1, 6, '0', NULL, NULL, NULL}, {1, 7, '0', NULL, NULL, NULL}, {1, 8, '0', NULL, NULL, NULL}},
                                     	 {{2, 0, '2', NULL, NULL, 1}, {2, 1, '0', NULL, NULL, NULL}, {2, 2, '0', NULL, NULL, NULL}, {2, 3, '0', NULL, NULL, NULL}, {2, 4, '0', NULL, NULL, NULL}, {2, 5, '0', NULL, NULL, NULL}, {2, 6, '0', NULL, NULL, NULL}, {2, 7, '0', NULL, NULL, NULL}, {2, 8, '0', NULL, NULL, NULL}},
                                     	 {{3, 0, '3', NULL, NULL, 1}, {3, 1, '0', NULL, NULL, NULL}, {3, 2, '0', NULL, NULL, NULL}, {3, 3, '0', NULL, NULL, NULL}, {3, 4, '0', NULL, NULL, NULL}, {3, 5, '0', NULL, NULL, NULL}, {3, 6, '0', NULL, NULL, NULL}, {3, 7, '0', NULL, NULL, NULL}, {3, 8, '0', NULL, NULL, NULL}},
                                    	 {{4, 0, '4', NULL, NULL, 1}, {4, 1, '0', NULL, NULL, NULL}, {4, 2, '0', NULL, NULL, NULL}, {4, 3, '0', NULL, NULL, NULL}, {4, 4, '0', NULL, NULL, NULL}, {4, 5, '0', NULL, NULL, NULL}, {4, 6, '0', NULL, NULL, NULL}, {4, 7, '0', NULL, NULL, NULL}, {4, 8, '0', NULL, NULL, NULL}},
                                    	 {{5, 0, '5', NULL, NULL, 1}, {5, 1, '0', NULL, NULL, NULL}, {5, 2, '0', NULL, NULL, NULL}, {5, 3, '0', NULL, NULL, NULL}, {5, 4, '0', NULL, NULL, NULL}, {5, 5, '0', NULL, NULL, NULL}, {5, 6, '0', NULL, NULL, NULL}, {5, 7, '0', NULL, NULL, NULL}, {5, 8, '0', NULL, NULL, NULL}},
                                    	 {{6, 0, '6', NULL, NULL, 1}, {6, 1, '0', NULL, NULL, NULL}, {6, 2, '0', NULL, NULL, NULL}, {6, 3, '0', NULL, NULL, NULL}, {6, 4, '0', NULL, NULL, NULL}, {6, 5, '0', NULL, NULL, NULL}, {6, 6, '0', NULL, NULL, NULL}, {6, 7, '0', NULL, NULL, NULL}, {6, 8, '0', NULL, NULL, NULL}},
                                    	 {{7, 0, '7', NULL, NULL, 1}, {7, 1, '0', NULL, NULL, NULL}, {7, 2, '0', NULL, NULL, NULL}, {7, 3, '0', NULL, NULL, NULL}, {7, 4, '0', NULL, NULL, NULL}, {7, 5, '0', NULL, NULL, NULL}, {7, 6, '0', NULL, NULL, NULL}, {7, 7, '0', NULL, NULL, NULL}, {7, 8, '0', NULL, NULL, NULL}},
                                   	 {{8, 0, '8', NULL, NULL, 1}, {8, 1, '0', NULL, NULL, NULL}, {8, 2, '0', NULL, NULL, NULL}, {8, 3, '0', NULL, NULL, NULL}, {8, 4, '0', NULL, NULL, NULL}, {8, 5, '0', NULL, NULL, NULL}, {8, 6, '0', NULL, NULL, NULL}, {8, 7, '0', NULL, NULL, NULL}, {8, 8, '0', NULL, NULL, NULL}}};
};

#endif
