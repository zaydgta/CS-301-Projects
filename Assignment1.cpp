// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Number_bucket.h"

// Constructor
Number_bucket::Number_bucket() {
	
	// Variables
	m = 0;
	bucket = {NULL};
};

// Constructor for file input
Number_bucket::Number_bucket(string inputFileName) {

	// Variables
	ifstream inputFile;
	int n;
	m = 0;
	bucket = {NULL};

	// Opens the input file
	inputFile.open(inputFileName);

	// Reads the data into the variable n then adds it into the stack
	while (inputFile >> n) {

		push(n);
	}
	
	// Closes the input file
	inputFile.close();
};


// Destructor
Number_bucket::~Number_bucket() {
};

// Checks whether or not the stack is empty
bool Number_bucket::isEmpty() const {
	
	if (bucket[m] == NULL) {
		return true;
	} else {
		return false;
	}
};

// Adds an integer into the stack.
void Number_bucket::push(int n) {

	bucket.push_back(n);
	m++;
};

// Removes the integer from the top of the stack.
void Number_bucket::pop() {
	
	if (m != 0) {
		bucket.pop_back();
		m--;
	}
};

// Shows the number of elements currently added to the stack.
int Number_bucket::get_size() const {
	
	return m;
};

// Return the int that is currently at the top of the stack.
int Number_bucket::top() const {
	
	if (m == 0) {
		return NULL;
	}

	return bucket.back();
};
    
int main() {

	// Variables
	ofstream outputFile;
	Number_bucket bucket("testDataInput.txt");

	// All test cases to be implemented
	// Test case 1

	cout << "The bucket is empty: 0 or 1 = " << bucket.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket.get_size() << endl;

	bucket.pop();
	cout << "POP!!!!" << endl;

	cout << "The bucket is empty: 0 or 1 = " << bucket.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket.get_size() << endl;

	bucket.pop();
	cout << "POP!!!!" << endl;

	cout << "The bucket is empty: 0 or 1 = " << bucket.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket.get_size() << endl;

	bucket.pop();
	cout << "POP!!!!" << endl;

	cout << "The bucket is empty: 0 or 1 = " << bucket.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket.get_size() << endl;

	// Opens the output file;
	outputFile.open("testDataOutput.txt");

	// Outputs the data into the output file
	while (bucket.top() != NULL){
		outputFile << bucket.top() << " ";
		bucket.pop();
	}

	// Closes the output file
	outputFile.close();

	// Ends the program
	return 0;
}
