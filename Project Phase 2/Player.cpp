// This cpp file contains the implementation for the player class type functions
#include "Player.h"
using namespace std;

// Player class constructor
Player::Player() {

    turn = true;
    win = false;
}

// Player class destructor
Player::~Player(){

}

// Player class functions
// Prompts the player to input their move
void Player::userInput(){
    
    cout << "Pick the checker piece you would like to move" << endl;
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
