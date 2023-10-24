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

        //cout << "Row in ID check is: " << checkRow << endl; // debug
        //cout << "Column in ID check is: " << checkColumn << endl; // debug

        if (checkRow == row && checkColumn == column) {
            //cout << "ID in ID check is: " << pieces[i].id << endl; // debug
            return pieces[i].id;
            
        }
    }
}

vector<Piece> Piece::updatePiece(int row, int column, int id, vector<Piece> pieces) {
    
    for (int i = 0; i < 12; i++) {
        //cout << "ID in update piece before change is : " << pieces[i].id << endl; // debug
        //cout << "Row in update piece before change is : " << pieces[i].row << endl; // debug
        //cout << "Column in update piece before change is : " << pieces[i].column << endl; // debug
        if (pieces[i].id == id) {
            pieces[i].row = row;
            pieces[i].column = column;
            //cout << "ID in update piece after change is : " << pieces[i].id << endl; // debug
            //cout << "Row in update piece after change is : " << pieces[i].row << endl; // debug
            //cout << "Column in update piece after change is : " << pieces[i].column << endl; // debug
            return pieces;
        }
    }
}

int Piece::returnRow(int pieceID, vector<Piece> pieces) {
    
    for (int i = 0; i < 12; i++) {
        if (pieces[i].id == pieceID) {
            return pieces[i].row;
            break;
        }
    }
    return 0;
}

int Piece::returnColumn(int pieceID, vector<Piece> pieces) {
    
    for (int i = 0; i < 12; i++) {
        if (pieces[i].id == pieceID) {
            return pieces[i].column;
            break;
        }
    }
    return 0;
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