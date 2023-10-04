// This cpp file contains the implementation for the Player class type functions
// Program libraries
#include "Player.h"
using namespace std;

// Player class constructor
Player::Player() {

    turn = true;
    win = false;
	row = '0';
	column = 'Z';
	id = "Player";
}

Player::Player(string ids) {

	turn = true;
	win = false;
	row = '0';
	column = 'Z';
	id = ids;
}

// Player class destructor
Player::~Player(){

}

// Player class functions
// Prompts the player to input their move
void Player::userInput(){
    
    cout << "Pick the checker piece you would like to move by inputting the row number and column letter (Ex: 3G)" << endl;
	cin >> row >> column;

	// Call the board object to detect if there is a piece on that space
	// The board will return empty or the piece number and if its the player's or the opponent's

	// Call the function that shows the available moves for the piece

	cout << "Please choose which square you want to move the piece to" << endl;

	char rowMoveTo, columnMoveTo;
	cin >> rowMoveTo >> columnMoveTo;

	// Call the piece function to move the current piece to the new location and update the board


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
