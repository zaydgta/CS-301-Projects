// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Permutations.h"

// Constructor
Permutations::Permutations() {

	n = 0;
	k = 0;
	num = { NULL };
};

// Constructor for file input
Permutations::Permutations(string inputFileName) {

	// Variables
	ifstream inputFile;
	int m;
	n = 0;
	k = 0;
	num = { NULL };

	// Opens the input file
	inputFile.open(inputFileName);

	// Reads the data into the variable m then adds it to the vector
	while (inputFile >> m) {

		add(n, m);
	}

	// Closes the input file
	inputFile.close();

	// Sorts the vector
	bubbleSort();
};

// Destructor
Permutations::~Permutations() {
};

// Sorts the vector using bubbleSort algorithm
// Include citationsssssssssssssssssssssssssss
void Permutations::bubbleSort(){
	
	int i, j;
	
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (num[j] > num[j + 1]) {

				swap(j, j+1);
			}
		}
	}

	k = num[n-1];
	cout << "k is equal to " << k << endl;
}

// Swaps the two integers
void Permutations::swap(int a, int b) {
	
	int temp = num[a];
	num[a] = num[b];
	num[b] = temp;
}


// Swaps all integers to get every permutation
void Permutations::allPermutations() {
	

	int i = 1;
	// k is the mobile element

	printPermutations();

	while (num[n-i] > num[n-i-1] && num[n-i] == k) {
		//cout << "k, num[n-1], num[n-2] are = " << k << ", " << num[n - 1] << ", " << num[n - 2] << endl;
		swap(n-i, n-i-1);
		i++;
	}

	printPermutations();
};


// Adds an integer into the vector.
void Permutations::add(int a, int b) {

	num.insert(num.begin() + a, b);
	n++;

	cout << num[a] << endl;
};

// Removes an integer from the vector.
void Permutations::remove(int a) {

	int i = 0;

	while (a != num[i]) {
	
		i++;
	}

	if (a == num[i]) {
		num.erase(num.begin() + i);
	}
};

// Shows the number of elements currently in the vector.
int Permutations::getSize() const {
	
	return n;
};

// Prints the vectors permutations
void Permutations::printPermutations() {
	
	int i = 0;
	
	while (i < n) {
		cout << num[i] << " ";
		i++;
	};

	cout << endl;
};

int main() {

	ofstream outputFile;
	Permutations group1;

	// adding elements to the vector
	cout << "adding numbers" << endl;
	group1.add(0, 8);
	group1.add(1, 5);
	group1.add(2, 3);
	group1.add(3, 1);

	// prints the size of the vector
	cout << "Size is: " << group1.getSize() << endl;

	// prints the contents of the vector
	group1.printPermutations();

	group1.bubbleSort();

	group1.printPermutations();

	cout << "///////////////////////////////" << endl;

	group1.allPermutations();

	// Ends the program
	return 0;
}
