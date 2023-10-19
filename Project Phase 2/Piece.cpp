// This cpp file contains the implementation for the Piece class type functions
// Program libraries
#include "Player.h"
#include "Piece.h"
#include "Board.h"
//#include "color.hpp"

////////////////////////////////////////////////////////

//What to do:
// Make a function that returns the id of the piece based on the user's row and column
// Make a function will access the piece at the given id to update its row and column of the piece
////////////////////////////////////////////////////////

// Piece class constructor
Piece::Piece() {

    id = 0;
    label = " ";
    row = 0;
    column = 0;
}

Piece::Piece(int ids, string labels, int rowNum, int columnNum){

    id = ids;
    label = labels;
    row = rowNum;
    column = columnNum;
}

// Piece class destructor
Piece::~Piece(){

}

// Returns the id of the piece given the user's row and column
int Piece::returnID(int row, int column, vector<Piece> pieces) {

    int checkRow, checkColumn;

    for (int i = 0; i < 12; i++) {
        checkRow = pieces[i].row;
        checkColumn = pieces[i].column;

        cout << "Row in ID check is: " << checkRow << endl; // debug
        cout << "Column in ID check is: " << checkColumn << endl; // debug

        if (checkRow == row && checkColumn == column) {
            cout << "ID in ID check is: " << pieces[i].id << endl; // debug
            return pieces[i].id;
            
        }
    }
}

void Piece::updatePiece(int row, int column, int id, vector<Piece> pieces) {
    
    for (int i = 0; i < 12; i++) {
        cout << "ID in update piece before change is : " << pieces[i].id << endl; // debug
        cout << "Row in update piece before change is : " << pieces[i].row << endl; // debug
        cout << "Column in update piece before change is : " << pieces[i].column << endl; // debug
        if (pieces[i].id == id) {
            pieces[i].row = row;
            pieces[i].column = column;
            cout << "ID in update piece after change is : " << pieces[i].id << endl; // debug
            cout << "Row in update piece after change is : " << pieces[i].row << endl; // debug
            cout << "Column in update piece after change is : " << pieces[i].column << endl; // debug
            break;
        }
    }
}