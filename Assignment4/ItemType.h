// The following declarations and definitions go into file
// ItemType.h.

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int MAX_ITEMS = 5;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType {

public:
	ItemType();
	RelationType ComparedTo(ItemType) const;
	void Print(std::ostream&) const;

    void InitializeSemester(int numOfAssignments, int numOfTests, int numOfFinalExam, int assignmentWeight, int testWeight, int finalExamWeight);
	void InitializeStudent(int number, std::string firstName, std::string lastName, int id);
	void InitializeGrades(int numOfAssignments, int numOfTests, int numOfFinalExams);
    void InitializeAssignments(int assignmentNumber, int grade);
    void InitializeTests(int tests[]);
    void InitializeFinalExams(int finalExams[]);


	//Temp
	//void printItem();

    // Order of student on the list
	int value;

    //Basic student info
	std::string fName;
	std::string lName;
	int idN;

    //Weights of assignment (must = 100%)
    int assignmentsW;
    int testsW;
    int finalExamsW;

    // Number of all assignments
    int numAssignments;
    int numTests;
    int numFinalExams;

    //Grades of all assignments
    std::vector<float> assignmentsG;
    std::vector<float> testsG;
    std::vector<float> finalExamsG;
    float finalG;
};

#endif
