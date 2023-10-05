// This cpp file contains the implementation for the Board class type functions
// Program libraries
//#include "Player.h"
#include "Board.h"
//#include "Piece.h"
using namespace std;

static int counter = 0; //NOT NEEDED, JUST FOR DEBUGGING

// Player class constructor
//CREATE THE LINESSSS
//◯, ●,○, 
Board::Board() {
    
}

// Player class destructor
Board::~Board(){

}

// Board class functions
// Functions to do: position check, promote check, update board, 

void Board::testingBoard(){  //NOT NEEDED, JUST FOR DEBUGGING------------------------------------------------
    
    int row, col;
    counter++;
    
    cout << "Enter something for Board " << counter <<".\n" << "Enter a row and column:\n";
    cin >> row >> col;
    
    board[--row][--col] = 'X';
}
//------------------------------------------------------------------------------------------------------------

//Prints the current location of the pieces on the board
void Board::printBoard() {

     for (int i=0; i < ROW; i++)
        {
            for (int x=0; x < COL; x++)
                cout << board[i][x] << " ";
            
            cout << endl;
        }

    cout << "print board: COMPLETED" << endl;
}

//Updates the position of the pieces after every turn 
void positionCheck() {
    
}

//Removes a piece from the board
void removePiece() {
    
}

//Checks the possible 