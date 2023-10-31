// This cpp file contains the implementation for the Board class type functions
// Program libraries
#include "Player.h"
#include "Piece.h"
#include "Board.h"
#include <windows.h>

// Player class constructor 
Board::Board() {
    
    board;
}

// Player class destructor
Board::~Board(){

}

// Board class functions
//Prints the current location of the pieces on the board
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
    board[row1][column1].value = ' ';
    board[row1][column1].status = false;

    // Updates the new location of the piece
    if (label == "Player 1") {
        board[row2][column2].value = '0';
        board[row2][column2].player = true;
        board[row2][column2].status = true;
    } else if (label == "Player 2") {
        board[row2][column2].value = '0';
        board[row2][column2].player = false;
        board[row2][column2].status = true;
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