// This cpp file contains the implementation for the Board class type functions
// Program libraries
#include "Player.h"
#include "Piece.h"
#include "Board.h"

// Player class constructor
//CREATE THE LINESSSS
//◯, ●,○, 
Board::Board() {
    
    board;
}

// Player class destructor
Board::~Board(){

}

// Board class functions
// Functions to do: position check, promote check, update board, 

//Prints the current location of the pieces on the board
//update one space before printing board
//create lines for board (https://stackoverflow.com/questions/4471714/pretty-print-a-table-in-c)
//color the board
void Board::printBoard() {
    
    for (int i = 0; i < 1; i++)
        {
            cout << setw(2);
            
            for (int x=0; x < COL; x++)
                cout << board[i][x].value << " |" << setw(2);
            
            cout << endl;    
            cout << "---|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    
     for (int i = 1; i < ROW; i++)
        {
            cout << setw(2);
            
            for (int x=0; x < COL; x++)
                cout << board[i][x].value << " |" << setw(2);
            
            cout << endl;    
            cout << "---|--------------------------------" << endl;
        }
    cout << endl;
}

void Board::updateBoard(int rowOld, int columnOld, int rowNew, int columnNew, string pieceLabel) {
    
    if (pieceLabel == "Player 1")
        board[rowOld][columnOld].value;

}

//Updates the position of the pieces after every turn 
void Board::positionCheck() {
    
    
}

//Removes a piece from the board
void Board::removePiece(int r, int c) {
    
    //if (board[r][c].status == 1)
    //{
        board[--r][--c].value = 'X'; //X is a placeholder
        board[--r][--c].status = 0; //space is now empty
    //}
    
}
