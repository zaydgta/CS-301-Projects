// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Number_bucket.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Work to be done
// Check if the input and output functions are working
// Create a test driver.cpp
// Create more constructors to include file inputs
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Constructor
Number_bucket::Number_bucket() {
	m = 0;
	bucket[100] = { NULL };
};

// Destructor
Number_bucket::~Number_bucket() {

};

// Checks whether or not the stack is empty
bool Number_bucket::isEmpty() const {
	
	if (bucket[0] == NULL) {
		return true;
	} else {
		return false;
	}
};

// Adds an integer into the stack.
void Number_bucket::push(int n) {

	bucket[m] = n;
	m++;
};

// Removes the integer from the top of the stack.
void Number_bucket::pop() {
	
	bucket[m] = NULL;
	m--;	
};

// Shows the number of elements currently added to the stack.
int Number_bucket::get_size() const {
	
	return m;
};

// Return the int that is currently at the top of the stack.
int Number_bucket::top() const {
	
	return bucket[m];
};
    
int main() {

	// Variables
	ifstream inputFile;
	ofstream outputFile:
	int n;
	Number_bucket bucket;

	// Opens the input file
	inputFile.open("testDataInput.txt");

	// Reads the data into the variable n then adds it into the stack
	while (inputFile.is_open()){
		inputFile >> n;
		bucket.push(n);
	}

	// Closes the input file
	inputFile.close();

	// All test cases to be implemented

	// Opens the output file;
	outputFile.open("testDataOutput.txt");

	// Outputs the data into the output file
	while (outputFile.is_open()){
		outputFile << n << endl;
	}

	// Closes the output file
	outputFile.close();

	// Ends the program
	return 0;
}
