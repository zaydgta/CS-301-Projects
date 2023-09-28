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

            // Variables
            int numOfAssignments, numOfTests, numOfFinalExams, assignmentsWeight, testsWeight, finalExamsWeight, totalWeight = 0;
            
            // Prompts the user for multiple things
            cout << "Input number of assignments(0-6): " << endl;
            cin >> numOfAssignments;

            cout << "Input number of tests(0-4): " << endl;
            cin >> numOfTests;

            cout << "Input number of final exams(0-1): " << endl;
            cin >> numOfFinalExams;
            
            // Checks if the total weight adds up to exactly 100%
            while (totalWeight != 100) {

                cout << "Input weight of programming assignments: " << endl;
                cin >> assignmentsWeight;

                cout << "Input weight of tests: " << endl;
                cin >> testsWeight;

                cout << "Input weight of final exam: " << endl;
                cin >> finalExamsWeight;

                totalWeight = assignmentsWeight + testsWeight + finalExamsWeight;

                if (totalWeight != 100) {
                    cout << "Total weight for assignments has exceeded 100%. Please re-enter the weights" << endl;
                }
            }

            // Initializes the itemType class with the required variables
            item.InitializeSemester(numOfAssignments, numOfTests, numOfFinalExams, assignmentsWeight, testsWeight, finalExamsWeight);

        } else if (command == "A") {
            
            // Variables
            string firstName, lastName;
            int id;
            
            // Prompts the user for multiple things
            cout << "Input student's first name: " << endl;
            cin >> firstName;
            
            cout << "Input student's last name: " << endl;
            cin >> lastName;
            
            cout << "Input student's id: " << endl;
            cin >> id;
            
            // Gets the length of the linked list(GradeBook1)
            int length = GradeBook1.GetLength();

            // Initializes the student information into the ItemType class
            item.InitializeStudent(length, firstName, lastName, id);

            // Adds the ItemType(item) into the linked list(GradeBook1) as a node
            GradeBook1.createStudent(item);
    
        } else if (command == "P") {
            
            int i = 0, number, grade;

            item = GradeBook1.GetNextItem();

            int numAssignments = item.numAssignments;

            GradeBook1.ResetList();

            while (i < numAssignments) {
                cout << "Which programming assignment's grade do you want to record?" << endl;
                cin >> number;

                GradeBook1.recordAssignment(number);
            }

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

    // Temporary print function
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
