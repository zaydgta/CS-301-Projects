// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Number_bucket.h"


	
// Constructor
Number_bucket::Number_bucket() {

};

// Destructor
Number_bucket::~Number_bucket() {

};

// Checks whether or not the stack is empty
bool Number_bucket::isEmpty() const {
	return 0;
};

// Adds an integer into the stack.
void Number_bucket::push(int n) {
	
};

// Removes the integer from the top of the stack.
void Number_bucket::pop() {
	
};

// Shows the number of elements currently added to the stack.
int Number_bucket::get_size() const {
	
};

// Return the int that is currently at the top of the stack.
int Number_bucket::top() const {
	
};
    
int main() {
	
	stack<int> bucket;
	bucket.push(5);
	bucket.top();
	//bucket.get_size();
	bucket.pop();
	bucket.top();


	return 0;
}