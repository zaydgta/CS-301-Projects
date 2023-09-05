#include "Permutations.h"

// Main function
int main() {
    
    // Variables
    int n;

    // Prints a message to the user
    cout << "Enter n (1 <= n <= 25): ";

    // Asks user for input
    cin >> n;

    // Checks for valid input
    while (n < 1 || n > 25) {
        cout << "Invalid input. n must be between 1 and 25." << endl;
        cin >> n;
    }

    // Creates a permutations object
    Permutations p(n);
    p.GeneratePermutations();

    // Ends program
    return 0;
}
