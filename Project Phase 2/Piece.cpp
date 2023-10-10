// This cpp file contains the implementation for the Piece class type functions
// Program libraries
#include "Piece.h"
using namespace std;


////////////////////////////////////////////////////////

//What to do:
// Make a function that returns the id of the piece based on the user's row and column
// Make a function will access the piece at the given id to update its row and column of the piece
////////////////////////////////////////////////////////

// Piece class constructor
Piece::Piece() {

    id = 0;
    label = "";
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