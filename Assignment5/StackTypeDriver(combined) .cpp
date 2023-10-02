/***
 Title: <StackDr.cpp>
 Author: <Nell Dale, Chip Weems, Tim Richards>
 Date: <9/29/2023>
 Code version: <Latest>
 Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
 *
 ***/

// Test driver
#include <iostream>
#include <fstream>
#include "StackType.h"
using namespace std;

int main() {
    
    ifstream inFile;             //file containing operations
    ifstream reverseInFile;      //file containing date to reverse
    ofstream outFile;            //file containing output
    ofstream reverseOutFile;     //file containing output for reverse
    string inFileNameReverse;    //input file external name for inverse
    string outFileNameReverse;   //output file external name for reverse
    string inFileName;           //input file external name
    string outFileName;          //output file external name
    string outputLabel;
    string command;              //operation to be executed
    
    int item;
    char reverseItem;
    StackType <int> stack(5);
    StackType <char> reverseStack(5);
    int numCommands;
    
    // Prompt for file names, read file names, and prepare files
    
    cout << "\nEnter name of input command file; press return." << endl;
    cin  >> inFileName;
    inFile.open(inFileName.c_str());
    
    cout << "Enter name of output file; press return." << endl;
    cin  >> outFileName;
    outFile.open(outFileName.c_str());
    
    cout << "Enter name of test run; press return." << endl;
    cin  >> outputLabel;
    outFile << outputLabel << endl;
    
    inFile >> command;
    numCommands = 0;
    
    while (command != "Quit"){
        try {
            
            if (command == "Push") {
                inFile >> item;
                stack.Push(item);
                
            } else if (command == "Pop") {
                stack.Pop();
                
            } else if (command == "Top") {
                item = stack.Top();
                outFile<< "Top element is " << item << endl;
                
            } else if (command == "IsEmpty") {
                if (stack.IsEmpty()) {
                    outFile << "Stack is empty." << endl;
                } else {
                    outFile << "Stack is not empty." << endl;
                }
                
            } else if (command == "IsFull") {
                if (stack.IsFull()) {
                    outFile << "Stack is full." << endl;
                } else {
                    outFile << "Stack is not full." << endl;
                }
                
            } else {
                cout << "Command not recognized." << endl;
                
            }
            
        } catch (FullStack) {
            outFile << "FullStack exception thrown." << endl;
        }
        
        catch (EmptyStack){
            outFile << "EmptyStack exception thrown." << endl;
        }
        
        numCommands++;
        cout <<  " Command number " << numCommands << " completed." << endl;
        inFile >> command;
    }
    
    cout << "Testing completed."  << endl;
    inFile.close();
    outFile.close();
    
    
    // Prompt for file names, read file names, and prepare files
    cout << "\n\nEnter name of input command file for reverse; press return." << endl;
    cin  >> inFileNameReverse;
    reverseInFile.open(inFileNameReverse.c_str());
    
    cout << "Enter name of output file; press return." << endl;
    cin  >> outFileNameReverse;
    reverseOutFile.open(outFileNameReverse.c_str());
    
    //Read items from the input file for reverse and push them onto the reverseStack
    while (reverseInFile >> reverseItem) {
        if (!reverseStack.IsFull())
            reverseStack.Push(reverseItem);
    }
    
    // Write reversed items to the reverse output file
    while (!reverseStack.IsEmpty()) {
        reverseItem = reverseStack.Top();
        reverseStack.Pop();
        reverseOutFile << reverseItem;
        
    }
    
    cout << "Reversing completed." << endl;
    reverseInFile.close();
    reverseOutFile.close();
    
    
    
    return 0;
}
