// This header file contains the Piece class type and related functions
#ifndef PIECE_H
#define PIECE_H

// Program libraries
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <string>
using namespace std;

class Piece {
public:
    // Class constructor
    Piece();
    Piece(int id, string label, int rowNum, int columnNum);

    // Class destructor
    ~Piece();

    // Piece functions
    // Layer 1
    void move();
    void remove();

    //Layer 2
    bool promote();
    void jump();

    //Layer 3
    bool moveCheck();
    bool jumpCheck();
    bool jumpedOver();

    //Layer 4
    bool multipleJumpCheck();
    void promoteMove();

private:

    int id;
    string label;
    int row;
    int column;
};


#endif