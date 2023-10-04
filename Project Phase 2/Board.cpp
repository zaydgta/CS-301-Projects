// This cpp file contains the implementation for the Board class type functions
// Program libraries
#include "Player.h"
#include "Board.h"
#include "Piece.h"
using namespace std;

const int ROW = 9;
const int COL = 9;

// Player class constructor
// create the board
//CREATE THE LINESSSS
//◯, ●,○, 
Board::Board() {

    char board[ROW][COL] = { '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                             '1', '0', '0', '0', '0', '0', '0', '0', '0',
                             '2', '0', '0', '0', '0', '0', '0', '0', '0',
                             '3', '0', '0', '0', '0', '0', '0', '0', '0',
                             '4', '0', '0', '0', '0', '0', '0', '0', '0',
                             '5', '0', '0', '0', '0', '0', '0', '0', '0',
                             '6', '0', '0', '0', '0', '0', '0', '0', '0',
                             '7', '0', '0', '0', '0', '0', '0', '0', '0',
                             '8', '0', '0', '0', '0', '0', '0', '0', '0' };

}

// Player class destructor
Board::~Board(){

}

// Board class functions
// Functions to do: position check, promote check, update board, 

//Prints the current location of the pieces on the board
void Board::printBoard() {

    for (int i = 0; i < ROW; i++) {
        for (int x = 0; x < COL; x++) {
            cout << board[i][x] << " " << endl;
        }
    }

    cout << "update board: COMPLETED" << endl;
}

//Updates the position of the pieces after every turn 
void positionCheck() {
    
}

//Removes a piece from the board
void remove() {
    
}

//Checks the possible 