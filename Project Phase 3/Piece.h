// This header file contains the Piece class type and related functions
#ifndef PIECE_H
#define PIECE_H

// Program libraries
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Piece {
public:

    // Class constructor
    Piece();
    Piece(int id, string label, int rowNum, int columnNum);

    // Class destructor
    ~Piece();

    // Piece functions
    int returnID(int row, int column, vector<Piece> pieces);
    vector<Piece> updatePiece(int row, int column, int id, vector<Piece> pieces);
    int returnRow(int pieceID, vector<Piece> pieces);
    int returnColumn(int pieceID, vector<Piece> pieces);
    string returnLabel(int pieceID, vector<Piece> pieces);

private:

    int id;
    string label;
    int row;
    int column;
};

#endif