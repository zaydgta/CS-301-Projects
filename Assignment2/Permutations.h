#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

class Permutations {

private:

	// Variables
	int n, k;
	vector<int> num;

public:

	// Constructor
	Permutations();

	// Constructor for file input
	Permutations(std::string inputFileName);

	// Destructor
	~Permutations();

	// Sorts the vector using bubbleSort algorithm
	void bubbleSort();

	// Swaps the two integers
	void swap(int a, int b);

	// Adds an integer to the vector.
	void add(int a, int b);

	// Removes an integer from the vector.
	void remove(int a);

	// Shows the number of elements currently in the vector.
	int getSize() const;

	// Swaps all integers to get every permutation
	void allPermutations();

	// Prints the vectors permutations
	void printPermutations();
};

#endif