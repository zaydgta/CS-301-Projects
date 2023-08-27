#ifndef NUMBER_BUCKET_H
#define NUMBER_BUCKET_H

#include <iostream>
using namespace std;

class Number_bucket {

public:

	// Constructor
	Number_bucket();

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