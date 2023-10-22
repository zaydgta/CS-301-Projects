// Assignment 6 main.cpp
#include <iostream>
#include <string>
using namespace std;

// Function to check whether string is palindrome
void isPalindrome(string S) {
    
    //change string to lowercase
    for (int i = 0; i < S.length(); i++){
        S[i] = tolower(S[i]);
    }
    
    // Variables
    int i = 0;
    int j = S.length() - 1;

    // Checks if the string is a palindrome
    if (S.length() == 1 || S.length() == 0) {
        cout << "String is a palindrome";
        return;
    }

    // Recursively calls the function
    if (S[i] == S[j]){
        S.erase(S.begin());
        S.erase(S.end() - 1);
        return isPalindrome(S);
    } else {
        cout << "String is not a palindrome.";
    }
}

// Driver Code
int main() {
    
    string S;
    cout << "Input a string:" << endl;
    getline(cin, S);
    isPalindrome(S);

    return 0;
}
