// This header file contains the Board class type and related functions
#ifndef BOARD_H
#define BOARD_H

// Program libraries
#include "Player.h"
#include "Piece.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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
	void printBoard();
    void updateBoard(int rowOld, int columnOld, int rowNew, int columnNew, string pieceLabel);
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

    //row1, row2, column1, column2, pieceID

checkerSpace board[ROW][COL] =  {{{0, 0, ' ', NULL, NULL, 1}, {0, 1, 'A', NULL, NULL,    1}, {0, 2, 'B', NULL, NULL,    1}, {0, 3, 'C', NULL, NULL,    1}, {0, 4, 'D', NULL, NULL,    1}, {0, 5, 'E', NULL, NULL,    1}, {0, 6, 'F', NULL, NULL,    1}, {0, 7, 'G', NULL, NULL,    1}, {0, 8, 'H', NULL, NULL,    1}},
	                	         {{1, 0, '1', NULL, NULL, 1}, {1, 1, ' ', NULL, NULL,    1}, {1, 2, '0', NULL, NULL, NULL}, {1, 3, ' ', NULL, NULL,    1}, {1, 4, '0', NULL, NULL, NULL}, {1, 5, ' ', NULL, NULL,    1}, {1, 6, '0', NULL, NULL, NULL}, {1, 7, ' ', NULL, NULL,    1}, {1, 8, '0', NULL, NULL, NULL}},
                                 {{2, 0, '2', NULL, NULL, 1}, {2, 1, '0', NULL, NULL, NULL}, {2, 2, ' ', NULL, NULL,    1}, {2, 3, '0', NULL, NULL, NULL}, {2, 4, ' ', NULL, NULL,    1}, {2, 5, '0', NULL, NULL, NULL}, {2, 6, ' ', NULL, NULL,    1}, {2, 7, '0', NULL, NULL, NULL}, {2, 8, ' ', NULL, NULL,    1}},
                                 {{3, 0, '3', NULL, NULL, 1}, {3, 1, ' ', NULL, NULL,    1}, {3, 2, '0', NULL, NULL, NULL}, {3, 3, ' ', NULL, NULL,    1}, {3, 4, '0', NULL, NULL, NULL}, {3, 5, ' ', NULL, NULL,    1}, {3, 6, '0', NULL, NULL, NULL}, {3, 7, ' ', NULL, NULL,    1}, {3, 8, '0', NULL, NULL, NULL}},
                                 {{4, 0, '4', NULL, NULL, 1}, {4, 1, ' ', NULL, NULL, NULL}, {4, 2, ' ', NULL, NULL,    1}, {4, 3, ' ', NULL, NULL, NULL}, {4, 4, ' ', NULL, NULL,    1}, {4, 5, ' ', NULL, NULL, NULL}, {4, 6, ' ', NULL, NULL,    1}, {4, 7, ' ', NULL, NULL, NULL}, {4, 8, ' ', NULL, NULL,    1}},
                                 {{5, 0, '5', NULL, NULL, 1}, {5, 1, ' ', NULL, NULL,    1}, {5, 2, ' ', NULL, NULL, NULL}, {5, 3, ' ', NULL, NULL,    1}, {5, 4, ' ', NULL, NULL, NULL}, {5, 5, ' ', NULL, NULL,    1}, {5, 6, ' ', NULL, NULL, NULL}, {5, 7, ' ', NULL, NULL,    1}, {5, 8, ' ', NULL, NULL, NULL}},
                                 {{6, 0, '6', NULL, NULL, 1}, {6, 1, '0', NULL, NULL, NULL}, {6, 2, ' ', NULL, NULL,    1}, {6, 3, '0', NULL, NULL, NULL}, {6, 4, ' ', NULL, NULL,    1}, {6, 5, '0', NULL, NULL, NULL}, {6, 6, ' ', NULL, NULL,    1}, {6, 7, '0', NULL, NULL, NULL}, {6, 8, ' ', NULL, NULL,    1}},
                                 {{7, 0, '7', NULL, NULL, 1}, {7, 1, ' ', NULL, NULL,    1}, {7, 2, '0', NULL, NULL, NULL}, {7, 3, ' ', NULL, NULL,    1}, {7, 4, '0', NULL, NULL, NULL}, {7, 5, ' ', NULL, NULL,    1}, {7, 6, '0', NULL, NULL, NULL}, {7, 7, ' ', NULL, NULL,    1}, {7, 8, '0', NULL, NULL, NULL}},
                                 {{8, 0, '8', NULL, NULL, 1}, {8, 1, '0', NULL, NULL, NULL}, {8, 2, ' ', NULL, NULL,    1}, {8, 3, '0', NULL, NULL, NULL}, {8, 4, ' ', NULL, NULL,    1}, {8, 5, '0', NULL, NULL, NULL}, {8, 6, ' ', NULL, NULL,    1}, {8, 7, '0', NULL, NULL, NULL}, {8, 8, ' ', NULL, NULL,    1}}};
};

#endif
