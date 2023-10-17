// This cpp file contains the main function for the project

// Program libraries
#include "Player.h"
#include "Piece.h"
#include "Board.h"
//#include <stdlib.h>
#include "color.hpp"
//#include "AI.h"

// Main function
int main() {    

    //system("Color 0A");

    // Variables
    int mode;
	Player player1("Player 1");
    Player player2("Player 2");
    //AI player2;
	bool player1WinCheck = false, player2WinCheck = false;
    Board board;
    
    // Prints these messages to the player on program start to choose mode
    cout << dye::green("Welcome to checkers!") << endl;
    cout << dye::green("This is a checkers game that utilizes the command prompt in order to play.") << endl;
    cout << dye::green("First select if you want to play against another player or against the AI.") << endl;
    cout << dye::green("(Input 1 for Player vs Player or 2 for Player vs AI): ");
    cin >> mode;
    
    
    // Creates a second player object or an AI object depending on user's input
    if (mode == 1){
        cout << endl << dye::blue("You have selected Player vs Player.") << endl;
        player2.playerTurn();
    } else if (mode == 2){
        cout << endl << dye::blue("You have selected Player vs AI.") << endl;
        //player2.AITurn();
    }
    
    // Prints out messages that give a small tutorial
    cout << dye::green("The board is a 8x8 board where each square is designated by a number followed by a letter (Ex: 3G)") << endl;
    cout << dye::green("You select the piece you want to move by choosing the square it occupies, then you choose where to move it") << endl;
    cout << dye::green("You alternate back and forth until one player achieves victory by consuming all of their opponent's pieces") << endl << endl;
    
    // Creates the player objects
    player1.createPieces(true);
    player2.createPieces(false);

    // A loop that will keep prompting the player and printing the board until a winner is found
	while (player1WinCheck == false || player2WinCheck == false){
        
		// Calls the function to get user input for player 1
        cout << dye::red("Player 1's turn:") << endl;
        player1.userInput();

		// Checks if player1 has won the game and updates the variables
        player1WinCheck = player1.playerWin();

        // Calls the function to get user input for player 2
        cout << dye::yellow("Player 2's turn:") << endl;
        player2.userInput();

        // Checks if player2 has won the game and updates the variables
        player2WinCheck = player2.playerWin();
    }
    
	// Checks who has won the game and outputs the winner
	if (player1WinCheck == true) {
		cout << dye::blue("Player 1 wins!") << endl;
	} else if (player2WinCheck == true) {
		cout << dye::blue("Player 2 wins!");
	}
    
    // Ends the program
    return 0;  
};
