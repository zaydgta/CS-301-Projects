// This cpp file contains the implementation for the Piece class type functions
// Program libraries
#include "Player.h"
#include "Piece.h"
#include "Board.h"

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

        if (checkRow == row && checkColumn == column) {
            return pieces[i].id;
        }
    }
}

void Piece::updatePiece(int row, int column, int id, vector<Piece> pieces) {
    
    for (int i = 0; i < 12; i++) {
        if (pieces[i].id == id) {
            pieces[i].row = row;
            pieces[i].column = column;
            break;
        }
    }
}