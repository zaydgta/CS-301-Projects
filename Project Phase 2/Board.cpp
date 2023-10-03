// This cpp file contains the implementation for the player class type functions
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

    char Board [ROW][COL] = { '', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                             '1',  '',  '',  '',  '',  '',  '',  '',  '',
                             '2',  '',  '',  '',  '',  '',  '',  '',  '',
                             '3',  '',  '',  '',  '',  '',  '',  '',  '',
                             '4',  '',  '',  '',  '',  '',  '',  '',  '',
                             '5',  '',  '',  '',  '',  '',  '',  '',  '',
                             '6',  '',  '',  '',  '',  '',  '',  '',  '',
                             '7',  '',  '',  '',  '',  '',  '',  '',  '',
                             '8',  '',  '',  '',  '',  '',  '',  '',  '' };

}

// Player class destructor
Board::~Board(){

}

// Board class functions
// Functions to do: position check, promote check, update board, 

//Prints the current location of the pieces on the board
void Board::printBoard(){
    
    for (int i=0; i < ROW; i++)
        {
            for (int x=0; x < COL; x++)
                cout << GAME[i][x] << " ";
            
            cout << endl;
        }
    cout << "update board: COMPLETED" << endl;
    
}

//Updates the position of the pieces after every turn 
void PositionCheck() {
    
}

//Removes a piece from the board
void Remove() {
    
}

//Checks the possible 


