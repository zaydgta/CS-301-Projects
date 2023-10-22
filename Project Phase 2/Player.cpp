// This cpp file contains the implementation for the Player class type functions
// // Program libraries
#include "Player.h"
#include "Piece.h"
#include "Board.h"
//#include "color.hpp"
#include <stdlib.h>

// Player class constructor
Player::Player() {

    turn = true;
    win = false;
    id = "Player";
}

Player::Player(string ids) {

	turn = true;
	win = false;
	id = ids;
}

// Player class destructor
Player::~Player(){

}

// Player class functions
// Prompts the player to input their move
void Player::userInput(){

    //system("Color 0A"); // debug
    
    int row, column, pieceID;
    char columnToConvert;
    Board board;

    // Call the board object to print it
    board.printBoard();

    // Asks user which piece to move
    cout << "Pick the checker piece you would like to move by inputting the row number and column letter(Ex: 3G): ";
	cin >> row >> columnToConvert;
    column = charToInt(columnToConvert);
    //cout << row << " " << column << endl; // debug
    
    // return the id of the piece that is at the square of the specified row and column number
    Piece allPieces;
    pieceID = allPieces.returnID(row, column, playerPieces);
    
    cout << "PieceID is " << pieceID << endl; // debug

	cout << endl << "Please choose which square you want to move the piece to: ";

    cin >> row >> columnToConvert;
    column = charToInt(columnToConvert);

    cout << endl;

    // update the row and column variables of the piece object with the specified id with the new row and column
    allPieces.updatePiece(row, column, pieceID, playerPieces);

	// Call the board again to update the whole board with the new piece position


	// End the player's turn
	playerTurn();
}

// Changes the flag if it's the player's current turn or not
void Player::playerTurn(){
    
    if (turn == true){
        turn = false;
    } else if (turn == false){
        turn = true;
    }
}

// Returns if the player has won or not
bool Player::playerWin(){
    return win;
}

string Player::playerID() {
	return id;
}

//Piece class createPiece function
void Player::createPieces(bool playerOrder) {

    // Variables
    string playerId = playerID();

    if (playerOrder == true) {

        Piece piece1(1, playerId, 8, 1);
        Piece piece2(2, playerId, 8, 3);
        Piece piece3(3, playerId, 8, 5);
        Piece piece4(4, playerId, 8, 7);
        Piece piece5(5, playerId, 7, 2);
        Piece piece6(6, playerId, 7, 4);
        Piece piece7(7, playerId, 7, 6);
        Piece piece8(8, playerId, 7, 8);
        Piece piece9(9, playerId, 6, 1);
        Piece piece10(10, playerId, 6, 3);
        Piece piece11(11, playerId, 6, 5);
        Piece piece12(12, playerId, 6, 7);

        playerPieces.push_back(piece1);
        playerPieces.push_back(piece2);
        playerPieces.push_back(piece3);
        playerPieces.push_back(piece4);
        playerPieces.push_back(piece5);
        playerPieces.push_back(piece6);
        playerPieces.push_back(piece7);
        playerPieces.push_back(piece8);
        playerPieces.push_back(piece9);
        playerPieces.push_back(piece10);
        playerPieces.push_back(piece11);
        playerPieces.push_back(piece12);
        
        //cout << true << endl; //debug

    } else if (playerOrder == false) {
        
        Piece piece1(1, playerId, 1, 2);
        Piece piece2(2, playerId, 1, 4);
        Piece piece3(3, playerId, 1, 6);
        Piece piece4(4, playerId, 1, 8);
        Piece piece5(5, playerId, 2, 1);
        Piece piece6(6, playerId, 2, 3);
        Piece piece7(7, playerId, 2, 5);
        Piece piece8(8, playerId, 2, 7);
        Piece piece9(9, playerId, 3, 2);
        Piece piece10(10, playerId, 3, 4);
        Piece piece11(11, playerId, 3, 6);
        Piece piece12(12, playerId, 3, 8);

        playerPieces.push_back(piece1);
        playerPieces.push_back(piece2);
        playerPieces.push_back(piece3);
        playerPieces.push_back(piece4);
        playerPieces.push_back(piece5);
        playerPieces.push_back(piece6);
        playerPieces.push_back(piece7);
        playerPieces.push_back(piece8);
        playerPieces.push_back(piece9);
        playerPieces.push_back(piece10);
        playerPieces.push_back(piece11);
        playerPieces.push_back(piece12);

        //cout << false << endl; //debug
    }
}

// Converts user input from char to int
int Player::charToInt(char columnChar) {
    
    columnChar = toupper(columnChar);

    if (columnChar == 'A') {
        return 1;
    } else if (columnChar == 'B') {
        return 2;
    } else if (columnChar == 'C') {
        return 3;
    } else if (columnChar == 'D') {
        return 4;
    } else if (columnChar == 'E') {
        return 5;
    } else if (columnChar == 'F') {
        return 6;
    } else if (columnChar == 'G') {
        return 7;
    } else if (columnChar == 'H') {
        return 8;
    }
    
    return 0;
}