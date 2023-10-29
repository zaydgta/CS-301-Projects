// This cpp file contains the implementation for the Board class type functions
// Program libraries
#include "Player.h"
#include "Piece.h"
#include "Board.h"
#include <windows.h>

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

    // COLORING TEXT
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 1; i++)
        {
            cout << setw(2);
            SetConsoleTextAttribute(console_color, 15);
            for (int x=0; x < COL; x++)
                cout << board[i][x].value << " |" << setw(2);
            
            cout << endl;    
            cout << "---|--------------------------------" << endl;
        }
    
     for (int i = 1; i < ROW; i++)
        {
            cout << setw(2);
            
            
            for (int x = 0; x < COL; x++) {
                
                if (board[i][x].player == true && x != 0) {
                    SetConsoleTextAttribute(console_color, 13);
                } else if (board[i][x].player == false && x != 0) {
                    SetConsoleTextAttribute(console_color, 3);
                }
                
                cout << board[i][x].value << setw(2);

                SetConsoleTextAttribute(console_color, 15);
                cout << " |" << setw(2);
                
            }
            
            cout << endl;    
            cout << "---|--------------------------------" << endl;
        }
    cout << endl;
}

void Board::updateBoard(int row1, int column1, int row2, int column2, string label) {
    
    // Updates previous location of the piece
    //cout << "DEBUG 1: " << board[row1][column1].value << endl; // DEBUG
    board[row1][column1].value = ' ';
    board[row1][column1].status = false;
    //cout << "DEBUG 2: " << board[row1][column1].value << endl; // DEBUG

    // Updates the new location of the piece
    if (label == "Player 1") {
        board[row2][column2].value = '0';
        board[row2][column2].player = true;
        board[row2][column2].status = true;
        //cout << "DEBUG 3: " << board[row2][column2].value << endl; // DEBUG
    } else if (label == "Player 2") {
        board[row2][column2].value = '0';
        board[row2][column2].player = false;
        board[row2][column2].status = true;
        //cout << "DEBUG 3: " << board[row2][column2].value << endl; // DEBUG
    }
}

//Updates the position of the pieces after every turn 
void Board::positionCheck() {
    
    
}

//Removes a piece from the board
void Board::removePiece(int r, int c) {
   
    board[r][c].value = ' '; // space is empty visually
    board[r][c].player = NULL; // space is not occupied by a player
    board[r][c].status = 0; //space is now empty
}
