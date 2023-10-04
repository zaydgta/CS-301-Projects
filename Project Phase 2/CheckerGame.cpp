// This cpp file contains the main function for the project

// Program libraries
#include "Player.h"
//#include "Piece.h"
//#include "Board.h"
//#include "AI.h"

// Main function
int main() {    

    // Variables
    int mode;
	Player player1;
	bool player1WinCheck = false, player2WinCheck = false;
    //Board board;
    
    // Prints these messages to the player on program start to choose mode
    cout << "Welcome to checkers!" << endl;
    cout << "This is a checkers game that utilizes the command prompt in order to play" << endl;
    cout << "First select if you want to play against another player or against the AI" << endl;
    cout << "Input 1 for Player vs Player or 2 for Player vs AI" << endl;
    cin >> mode;
    
    // Creates a second player object or an AI object depending on user's input
    if (mode == 1){
        cout << "You have selected Player vs Player" << endl;
        Player player2;
        player2.playerTurn();
    } else if (mode == 2){
        cout << "You have selected Player vs AI" << endl;
        //AI player2;
        //player2.AITurn();
    }
    
    // Prints the board and give a small tutorial
    cout << "Here's the current checker board" << endl;
    //board.printBoard();
    cout << "The board is a 8x8 board where each square is designated by a letter plus a number (Ex: 3G)" << endl;
    cout << "You select the piece you want to move by choosing the square it occupies, then you choose where to move it" << endl;
    cout << "You alternate back and forth until one player achieves victory by consuming all of their opponent's pieces" << endl;
    
    // A loop that will keep prompting the player and printing the board until a winner is found
	while (player1WinCheck == false || player2WinCheck == false){
        
		// Calls the function to get user input
        player1.userInput();

		//player1.createPieces();

		// Checks if a player has won the game and updates the variables
		player1WinCheck = player1.playerWin();
		player2WinCheck = player2.playerWin();
    }
    
	// Checks who has won the game and outputs the winner
	if (player1WinCheck == true) {
		cout << "Player 1 wins!" << endl;
	} else if (player2WinCheck == true) {
		cout << "Player 2 wins!";
	}
    
    // Ends the program
    return 0;  
};
