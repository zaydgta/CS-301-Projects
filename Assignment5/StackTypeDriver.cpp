/***
 Title: <StackDr.cpp>
 Author: <Nell Dale, Chip Weems, Tim Richards>
 Date: <9/29/2023>
 Code version: <Latest>
 Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
 *
 ***/

// Test driver (StackTypeDriver.cpp)
#include <iostream>
#include <fstream>
#include "StackType.h"
using namespace std;

// Main function
int main(){
    
    // Variables
    ifstream inFile;             //file containing operations
    ofstream outFile;            //file containing output
    string inFileName;           //input file external name
    string outFileName;          //output file external name
    
    char item;
    StackType <char> stack;

    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input command file; press return." << endl;
    cin  >> inFileName;
    inFile.open(inFileName.c_str());
    
    cout << "Enter name of output file; press return." << endl;
    cin  >> outFileName;
    outFile.open(outFileName.c_str());
    
    // Read items from the input file and push them into the stack
    while (inFile >> item){
        if (!stack.IsFull()){
            stack.Push(item);
        }
    }
    
    // Outputs the files from the stack into the
    while (!stack.IsEmpty()){
        item = stack.Top();
        outFile << item;
        stack.Pop();
    }
    
    cout << "Reversing completed." << endl;
    inFile.close();
    outFile.close();
    
    return 0;
}
