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
	Number_bucket bucket1("testDataInput1.txt");
	Number_bucket bucket2("testDataInput2.txt");
	Number_bucket bucket3("testDataInput3.txt");
	Number_bucket bucket4("testDataInput4.txt");
	Number_bucket bucket5("testDataInput5.txt");

	// All test cases
	// Test case for bucket 1 (Adding numbers from the file to the bucket then outputting to a file)

	cout << "The bucket is empty: 0 or 1 = " << bucket1.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket1.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket1.get_size() << endl;

	bucket1.pop();
	cout << "POP!!!!" << endl;

	cout << "The bucket is empty: 0 or 1 = " << bucket1.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket1.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket1.get_size() << endl;

	bucket1.pop();
	cout << "POP!!!!" << endl;

	cout << "The bucket is empty: 0 or 1 = " << bucket1.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket1.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket1.get_size() << endl;

	bucket1.pop();
	cout << "POP!!!!" << endl;

	cout << "The bucket is empty: 0 or 1 = " << bucket1.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket1.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket1.get_size() << endl;

	// Opens the output file for bucket 1;
	outputFile.open("testDataOutput1.txt");

	// Outputs the data by popping the elements of the bucket into the output file
	//while (bucket1.top() != NULL){
	while (bucket1.isEmpty() == false){
		
		outputFile << bucket1.top() << " ";
		bucket1.pop();
	}

	if (bucket1.isEmpty() == true){
		outputFile << "The bucket is empty" << endl;
	}

	// Closes the output file for bucket 1
	outputFile.close();


	// Test case for bucket 2 (Adding numbers from a file then popping only one number then outputting to a file)
	
	// Test case for bucket 3 (Adding numbers from a file then popping all of them making the bucket empty then outputting to a file)
	
	// Test case for bucket 4 (Opening an empty input file then outputting)
	
	// Test case for bucket 5 (Adding big amount of numbers from a file and adding numbers
	// manually then performing a bunch of different operations then outputting result)





	
	// Ends the program
	return 0;
}
