// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "GradeBook.h"
using namespace std;

void printGradeBook(ofstream& outFile, GradeBook& list);

int main(){

    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output
    string inFileName;     // input file external name
    string outFileName;    // output file external name
    string outputLabel;
    string command;        // operation to be executed
    int number;
    ItemType item;
    GradeBook GradeBook1;
    bool found;
    int numCommands;

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
    numCommands = 0;

    while (command != "Q"){
        if (command == "S") {
        /*
            inFile >> number;
            item.Initialize(number);
            list.DeleteItem(item);
            item.Print(outFile);
            outFile << " is deleted" << endl;
        */
        } else if (command == "A") {
            
            string firstName, lastName;
            int id;
            
            cout << "Input student's first name: " << endl;
            cin >> firstName;
            
            cout << "Input student's last name: " << endl;
            cin >> lastName;
            
            cout << "Input student's id: " << endl;
            cin >> id;
            
            int length = GradeBook1.GetLength();

            item.InitializeStudent(length, firstName, lastName, id);

            GradeBook1.createStudent(item);
    
        } else if (command == "P") {
        /*
            outFile << "Length is " << list.GetLength() << endl;
        */
        } else if (command == "T") {
        /*
            if (list.IsFull()) {
                outFile << "List is full." << endl;
            } else {
                outFile << "List is not full." << endl;

            }
            */

        } else if (command == "F") {
        /*
            list.MakeEmpty();
            outFile << "List is empty." << endl;
        */
        } else if (command == "C") {
        /*
            PrintList(outFile, list);
        */
        } else if (command == "G"){


        } else if (command == "O"){

        }


        else {
            cout << "Command not recognized." << endl;
        }

        numCommands++;
        cout <<  " Command number " << numCommands << " completed." << endl;
        inFile >> command;

    };

    printGradeBook(outFile, GradeBook1);

    cout << "Testing completed."  << endl;
    inFile.close();
    outFile.close();
    return 0;
}

// Pre:  list has been initialized.
//       dataFile is open for writing.
// Post: Each component in list has been written to dataFile.
//       dataFile is still open.
void printGradeBook(ofstream& dataFile, GradeBook& GradeBook1) {

    GradeBook1.ResetList();
    int length = GradeBook1.GetLength();
    for (int counter = 1; counter <= length; counter++){

        ItemType item;
        item = GradeBook1.GetNextItem();
        item.Print(dataFile);
        dataFile << endl;
    }

    dataFile << endl;

}
