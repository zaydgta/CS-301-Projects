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

	// Opens the output file for bucket 1;
	cout << "Opening output file 1" << endl;
	outputFile.open("testDataOutput1.txt");

	// Outputs the data by popping the elements of the bucket into the output file
	if (bucket1.isEmpty() == true){
		outputFile << "The bucket is empty" << endl;
	}
	
	while (bucket1.isEmpty() == false){
		
		outputFile << bucket1.top() << " ";
		bucket1.pop();
	}

	// Closes the output file for bucket 1
	outputFile.close();
	cout << "Closing output file 1" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Test case for bucket 2 (Adding numbers from a file then popping only one number then outputting to a file)
	cout << "The bucket is empty: 0 or 1 = " << bucket2.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket2.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket2.get_size() << endl;

	bucket2.pop();
	cout << "POP!!!!" << endl;
    
    cout << "The bucket is empty: 0 or 1 = " << bucket2.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket2.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket2.get_size() << endl;

	// Opens the output file for bucket 2;
	cout << "Opening output file 2" << endl;
	outputFile.open("testDataOutput2.txt");

	// Outputs the data by popping the elements of the bucket into the output file
	if (bucket2.isEmpty() == true){
		outputFile << "The bucket is empty" << endl;
	}
	while (bucket2.isEmpty() == false){
		
		outputFile << bucket2.top() << " ";
		bucket2.pop();
	}

	// Closes the output file for bucket 2
	outputFile.close();
	cout << "Closing output file 2" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Test case for bucket 3 (Adding numbers from a file then popping all of them making the bucket empty then outputting to a file)
	cout << "Opening output file 3" << endl;
	outputFile.open("testDataOutput3.txt");

	// Outputs the data by popping the elements of the bucket into the output file
	while (bucket3.isEmpty() == false){
	    
	    cout << "The bucket is empty: 0 or 1 = " << bucket3.isEmpty() << endl;
	    cout << "The number on top of the bucket is currently = " << bucket3.top() << endl;
	    cout << "The current size of the bucket is currently = " << bucket3.get_size() << endl;
		bucket3.pop();
	}

	while (bucket3.isEmpty() == false){
		
		outputFile << bucket3.top() << " ";
	}

	if (bucket3.isEmpty() == true){
		outputFile << "The bucket is empty" << endl;
	}

	// Closes the output file for bucket 3
	outputFile.close();
	cout << "Closing output file 3" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	// Test case for bucket 4 (Opening an empty input file then outputting)
	cout << "The bucket is empty: 0 or 1 = " << bucket4.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket4.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket4.get_size() << endl;

	// Opens the output file for bucket 4;
	cout << "Opening output file 4" << endl;
	outputFile.open("testDataOutput4.txt");

	// Outputs the data by popping the elements of the bucket into the output file
	if (bucket4.isEmpty() == true){
		outputFile << "The bucket is empty" << endl;
	}
	
	while (bucket4.isEmpty() == false){
		
		outputFile << bucket4.top() << " ";
		bucket4.pop();
	}

	// Closes the output file for bucket 4
	outputFile.close();
	cout << "Closing output file 4" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	// Test case for bucket 5 (Adding big amount of numbers from a file and adding numbers
	// manually then performing a bunch of different operations then outputting result)
    cout << "The bucket is empty: 0 or 1 = " << bucket5.isEmpty() << endl;
	cout << "The number on top of the bucket is currently = " << bucket5.top() << endl;
	cout << "The current size of the bucket is currently = " << bucket5.get_size() << endl;
	
	// Adds a number to bucket5
	bucket5.push(5000);
	cout << "The number on top of the bucket is currently = " << bucket5.top() << endl;
	
	// Adds a negative number to bucket5
	bucket5.push(-23);
    cout << "The number on top of the bucket is currently = " << bucket5.top() << endl;
    cout << "The current size of the bucket is currently = " << bucket5.get_size() << endl;
    
    // Empties bucket5
    while (bucket5.isEmpty() == false){
	
		bucket5.pop();
	}
    
    cout << "The current size of the bucket is currently = " << bucket5.get_size() << endl;
    
    // Adds a number to the bucket
    bucket5.push(-567843);
    cout << "The number on top of the bucket is currently = " << bucket5.top() << endl;
    cout << "The current size of the bucket is currently = " << bucket5.get_size() << endl;
    
    
	// Opens the output file for bucket 5;
	cout << "Opening output file 5" << endl;
	outputFile.open("testDataOutput5.txt");

	// Outputs the data by popping the elements of the bucket into the output file
	if (bucket5.isEmpty() == true){
		outputFile << "The bucket is empty" << endl;
	}
	
	while (bucket5.isEmpty() == false){
		
		outputFile << bucket5.top() << " ";
		bucket5.pop();
	}

    // Closes the output file for bucket 5
	outputFile.close();
	cout << "Closing output file 5" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

	// Ends the program
	return 0;
}
