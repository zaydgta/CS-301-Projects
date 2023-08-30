#ifndef NUMBER_BUCKET_H
#define NUMBER_BUCKET_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

class Number_bucket {

private:

	// Variables
	int m;
	vector<int> bucket;

public:

	// Constructor
	Number_bucket();

	// Constructor for file input
	Number_bucket(std::string inputFileName);

	// Destructor
	~Number_bucket();

	// Checks whether or not the stack is empty
	bool isEmpty() const;

	// Adds an integer into the stack.
	void push(int n);

	// Removes the integer from the top of the stack.
	void pop();

	// Shows the number of elements currently added to the stack.
	int get_size() const;

	// Return the int that is currently at the top of the stack.
	int top() const;

};

#endif
