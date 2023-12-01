/***
Title: <sortDr.h>
Author: <Nell Dale, Chip Weems, Tim Richards>
Date: <11/30/2023>
Code version: <Latest>
Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
*
***/

// This program is a sorting algorithm tester.
// Input are sorting algorithm names plus Refresh for resetting the values to be sorted to their previous values and Reinitialize for creating a new set of values.
const int SIZE = 50000;        // SIZE should be a multiple of 10.
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "SelectionSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include <chrono>

using namespace std;
typedef int ItemType;

void Print(ofstream&, int[]);	// Prints array
void InitValues(int[]);			// Creates random array 
void CopyValues(int[], int[]);	// Makes a copy of random array
void Swap(ItemType& item1, ItemType& item2);

int main(){

    // Variables
    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output
    string inFileName;     // input file external name
    string outFileName;    // output file external name
    string outputLabel;     
    string command;        // operation to be executed
    ItemType values[SIZE];
    int numCommands;
    ItemType copyValues[SIZE];
 
    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input command file; press return." << endl;
    cin  >> inFileName;
    inFile.open(inFileName.c_str());

    cout << "Enter name of output file; press return." << endl;
    cin  >> outFileName;
    outFile.open(outFileName.c_str());

    cout << "Enter name of test run; press return." << endl;
    cin  >> outputLabel;
    outFile << outputLabel << endl;

    inFile >> command;
    InitValues(values);
    CopyValues(values, copyValues);
    outFile << "Initial values" << endl;
    Print(outFile, values);

    numCommands = 0;

    while (command != "Quit"){ 
        if (command == "SelectionSort"){

            chrono::time_point<chrono::system_clock> start;
            chrono::time_point<chrono::system_clock> end;

            start = chrono::system_clock::now();            // Record start time

            SelectionSort(values, SIZE - 1);                // Run the sort

            end = chrono::system_clock::now();              // Record end time

            chrono::duration<float> elapsed = end - start;  // Calculate and report time

            outFile << "Results from SelectionSort: " << endl;
            Print(outFile, values);

            outFile << "Execution time in seconds = " << elapsed.count() << endl << endl; 

        } else if (command == "BubbleSort"){
            
            chrono::time_point<chrono::system_clock> start;
            chrono::time_point<chrono::system_clock> end;

            start = chrono::system_clock::now();            // Record start time

            BubbleSort(values, SIZE - 1);                   // Run the sort

            end = chrono::system_clock::now();              // Record end time

            chrono::duration<float> elapsed = end - start;  // Calculate and report time

            outFile << "Results from BubbleSort: " << endl;
            Print(outFile, values);

            outFile << "Execution time in seconds = " << elapsed.count() << endl << endl;

        } else if (command == "MergeSort"){
            
            chrono::time_point<chrono::system_clock> start;
            chrono::time_point<chrono::system_clock> end;

            start = chrono::system_clock::now();            // Record start time
                
            MergeSort(values, 0, SIZE - 1);                 // Run the sort

            end = chrono::system_clock::now();              // Record end time

            chrono::duration<float> elapsed = end - start;  // Calculate and report time

            outFile << "Results from MergeSort: " << endl;
            Print(outFile, values);

            outFile << "Execution time in seconds = " << elapsed.count() << endl << endl;

        } else if (command == "HeapSort"){

            chrono::time_point<chrono::system_clock> start;
            chrono::time_point<chrono::system_clock> end;

            start = chrono::system_clock::now();            // Record start time

            HeapSort(values, SIZE);                         // Run the sort

            end = chrono::system_clock::now();              // Record end time

            chrono::duration<float> elapsed = end - start;  // Calculate and report time

            outFile << "Results from HeapSort: " << endl;
            Print(outFile, values);

            outFile << "Execution time in seconds = " << elapsed.count() << endl << endl;

        } else if (command ==  "Refresh"){
            CopyValues(copyValues, values);

        } else if (command == "ReInitialize"){
            InitValues(values);
            CopyValues(values, copyValues);
            outFile << endl << "Initial Values: " << endl;
            Print(outFile, values);

        } else {
            outFile << "Input not recognized." << endl;  
        }
    
        numCommands++;
        cout <<  " Command " << command << " completed." << endl;
        inFile >> command;
    }
 
    cout << "Testing completed."  << endl;
    inFile.close();
    outFile.close();
    return 0;
}

// initializes the values array with random integers from 0 to 99
void InitValues(int values[]){
    for (int index = 0; index < SIZE; index++){
        values[index] = (std::rand() % 50000);
    }
}

void Print(ofstream& outFile, int values[]) {
    using namespace std;
    for (int count = 0; count < SIZE; count = count + 10){
        outFile << values[count] << ", " << values[count + 1] << ", " << values[count + 2] << ", "
        << values[count + 3] << ", " << values[count + 4] << ", " << values[count + 5] << ", "
        << values[count + 6] << ", " << values[count + 7] << ", " << values[count + 8]
        << ", " << values[count + 9] << endl << endl;
    }
}      

// Post: Contents of item1 and item2 have been swapped.
void Swap(ItemType& item1, ItemType& item2){
  
    ItemType tempItem;
    tempItem = item1;
    item1 = item2;
    item2 = tempItem;
}

void CopyValues(int inData[], int outData[]){
    for (int count = 0; count < SIZE; count++) {
        outData[count] = inData[count];
    }
}    