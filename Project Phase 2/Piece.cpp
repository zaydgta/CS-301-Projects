// This cpp file contains the implementation for the Piece class type functions
// Program libraries
#include "Player.h"
#include "Piece.h"
#include "Board.h"

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
    return -1;
}

vector<Piece> Piece::updatePiece(int row, int column, int id, vector<Piece> pieces) {
    
    for (int i = 0; i < 12; i++) {
        if (pieces[i].id == id) {
            pieces[i].row = row;
            pieces[i].column = column;
            return pieces;
        }
    }
    return pieces;
}

int Piece::returnRow(int pieceID, vector<Piece> pieces) {
    
    for (int i = 0; i < 12; i++) {
        if (pieces[i].id == pieceID) {
            return pieces[i].row;
            break;
        }
    }
    return -1;
}

int Piece::returnColumn(int pieceID, vector<Piece> pieces) {
    
    for (int i = 0; i < 12; i++) {
        if (pieces[i].id == pieceID) {
            return pieces[i].column;
            break;
        }
    }
    return -1;
}

string Piece::returnLabel(int pieceID, vector<Piece> pieces) {
    
    for (int i = 0; i < 12; i++) {
        if (pieces[i].id == pieceID) {
            return pieces[i].label;
            break;
        }
    }
    return "Nothing";
}