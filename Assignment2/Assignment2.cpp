// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Permutations.h"

// Constructor
Permutations::Permutations() {

	n = 0;

	num = { NULL };
};

// Constructor for file input
Permutations::Permutations(string inputFileName) {

	// Variables
	ifstream inputFile;
	int m;
	n = 0;
	num = { NULL };

	// Opens the input file
	inputFile.open(inputFileName);

	// Reads the data into the variable m then adds it to the vector
	while (inputFile >> m) {

		add(m, n);
		n++;
	}

	// Closes the input file
	inputFile.close();
};

// Destructor
Permutations::~Permutations() {
};

// Swaps the two integers
void Permutations::swap(int a, int b) {

};

// Adds an integer into the vector.
void Permutations::add(int a, int b) {

	num.insert(num.begin() + a, b);
};

// Removes an integer from the vector.
void Permutations::remove(int a) {

	num.erase(num.begin() + a);
};

// Shows the number of elements currently in the vector.
int Permutations::getSize() const {
	
	return n;
};

// Prints the vectors permutations
void Permutations::printPermutations() {
	
	int i = 0;
	
	while (i < n) {

	};
};


int main() {

	// Ends the program
	return 0;
}
