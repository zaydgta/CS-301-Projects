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

    inFile >> command;
    numCommands = 0;

    while (command != "Q"){
        if (command == "S") {

            // Variables
            int numOfAssignments = -1, numOfTests = -1, numOfFinalExams = -1, assignmentsWeight = -1, testsWeight = -1, finalExamsWeight = -1, totalWeight = 0;

            // Checks if the number of assignments exceed the range
            while (numOfAssignments < 0 || numOfAssignments > 6 || numOfTests < 0 || numOfTests > 4 || numOfFinalExams < 0 || numOfFinalExams > 1){

                // Prompts the user for multiple things
                cout << "Input number of assignments(0-6): " << endl;
                cin >> numOfAssignments;

                cout << "Input number of tests(0-4): " << endl;
                cin >> numOfTests;

                cout << "Input number of final exams(0-1): " << endl;
                cin >> numOfFinalExams;

                if (numOfAssignments < 0 || numOfAssignments > 6 || numOfTests < 0 || numOfTests > 4 || numOfFinalExams < 0 || numOfFinalExams > 1){
                    cout << "The number of assignments, tests, and final exams is outside of the required range. Please re-enter them." << endl;
                }
            }

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

			item.InitializeGrades(numOfAssignments, numOfTests, numOfFinalExams);

        } else if (command == "A") {

            // Variables
            string firstName, lastName;
            int id;

            // Prompts the user for multiple things
            cout << "Input student's first name: " << endl;
            cin >> firstName;

            cout << "Input student's last name: " << endl;
            cin >> lastName;

            cout << "Input student's ID: " << endl;
            cin >> id;

            // Gets the length of the linked list(GradeBook1)
            int length = GradeBook1.GetLength();

            // Initializes the student information into the ItemType class
            item.InitializeStudent(length, firstName, lastName, id);

            // Adds the ItemType(item) into the linked list(GradeBook1) as a node
            GradeBook1.createStudent(item);

        } else if (command == "P") {

            int number, grade, numAssignments;
            bool taken = false;

            item = GradeBook1.GetNextItem();

            numAssignments = item.numAssignments;

			vector<int> assignmentNumber;

			assignmentNumber.resize(numAssignments);

            for (int i = 0; i < numAssignments; i++) {

                cout << "Which programming assignment's grade do you want to record? (Number of assignments is " << numAssignments << ")" << endl;
                cin >> number;

				for (int j = 0; j < assignmentNumber.size(); j++) {
				
					if (number == assignmentNumber[j]) {
                        taken = true;
						cout << "Programming assignment " << number << " has already been graded. Please choose a different one" << endl;
						i--;
					} 
				}

                if (taken != true) {
                    GradeBook1.recordAssignment(number);
                    assignmentNumber.push_back(number);
                }

                taken = false;
            }

        } else if (command == "T") {
            
            int number, grade, numTests;
            bool taken = false;

            item = GradeBook1.GetNextItem();

            numTests = item.numTests;

            vector<int> testNumber;

            testNumber.resize(numTests);

            for (int i = 0; i < numTests; i++) {

                cout << "Which test's grade do you want to record? (Number of tests is " << numTests << ")" << endl;
                cin >> number;

                for (int j = 0; j < testNumber.size(); j++) {

                    if (number == testNumber[j]) {
                        taken = true;
                        cout << "Test " << number << " has already been graded. Please choose a different one" << endl;
                        i--;
                    }
                }

                if (taken != true) {
                    GradeBook1.recordTest(number);
                    testNumber.push_back(number);
                }

                taken = false;
            }

        } else if (command == "F") {
            
            int number, grade, numFinalExams;
            bool taken = false;

            item = GradeBook1.GetNextItem();

            numFinalExams = item.numFinalExams;

            if (numFinalExams == 0) {
                cout << "There is no final exam to grade" << endl;
            } else if (numFinalExams == 1) {
                number = 1;
                GradeBook1.recordFinalExam(number);
            }

        } else if (command == "C") {
        
            int id, grade;
            char choice;

            cout << "Input students ID:" << endl;
            cin >> id;

            cout << "Input new grade:" << endl;
            cin >> grade;

            cout << "Which type of grade would you like to change? (P = Programming Assignment, T = Test, F = Final Exam)" << endl;
            cin >> choice;

            GradeBook1.changeGrade(id, grade, choice);
            
            cout << "Your grade has been changed" << endl;

        } else if (command == "G"){

            GradeBook1.calculateFinalGrade();

        } else if (command == "O") {

            outFileName = "Grades.out";
            outFile.open(outFileName.c_str());
            printGradeBook(outFile, GradeBook1);
            outFile.close();

        } else if (command == "Q") {
            
            outFileName = "Grades.dat";
            outFile.open(outFileName.c_str());
            printGradeBook(outFile, GradeBook1);
            outFile.close();
        
        } else {
            cout << "Command not recognized." << endl;
        }

        numCommands++;
        cout <<  "Command number " << numCommands << " completed." << endl;
        inFile >> command;
    };

    cout << "Testing completed."  << endl;
    inFile.close();
    
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
