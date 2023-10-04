// This cpp file contains the implementation for the Piece class type functions
// Program libraries
#include "Piece.h"
using namespace std;

// Piece class constructor
Piece::Piece() {

    id = 0;
    label = "";
}

Piece::Piece(int ids, string labels){

    id = ids;
    label = labels;
}

// Piece class destructor
Piece::~Piece(){

}

//Piece class createPiece function
void createPieces(Player player){
    
    // Variables
    string playerId = player.playerID();
    Piece piece1(1, playerId);
    Piece piece2(2, playerId);
    Piece piece3(3, playerId);
    Piece piece4(4, playerId);
    Piece piece5(5, playerId);
    Piece piece6(6, playerId);
    Piece piece7(7, playerId);
    Piece piece8(8, playerId);
    Piece piece9(9, playerId);
    Piece piece10(10, playerId);
    Piece piece11(11, playerId);
    Piece piece12(12, playerId);
}