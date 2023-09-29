// The following definitions go into file ItemType.cpp.
#include <fstream>
#include <iostream>
#include "ItemType.h"


ItemType::ItemType() {

    // Order of student on the list
    value = 0;

    //Basic student info
    fName = " ";
    lName = " ";
    idN = 0;

    //Weights of assignment (must = 100%)
    assignmentsW = 0;
    testsW = 0;
    finalExamsW = 0;

    // Number of all assignments
    numAssignments = 0;
    numTests = 0;
    numFinalExams = 0;

    // Grades of all assignments
    assignmentsG;
    testsG;
    finalExamsG;
    finalG = 0;
}

// Compares the ItemType by last name then first name instead of value
RelationType ItemType::ComparedTo(ItemType otherItem) const {

    int lastNameComp = lName.compare(otherItem.lName);

    if (lastNameComp < 0) {
        return LESS;
    } else if (lastNameComp> 0) {
        return GREATER;
    } else {

        int firstNameComp = fName.compare(otherItem.fName);

        if (firstNameComp < 0) {
            return LESS;
        } else if (firstNameComp > 0) {
            return GREATER;
        } else {
            return EQUAL;
        }
    }
}

void ItemType::InitializeSemester(int numOfAssignments, int numOfTests, int numOfFinalExams, int assignmentWeight, int testWeight, int finalExamWeight) {
    numAssignments = numOfAssignments;
    numTests = numOfTests;
    numFinalExams = numOfFinalExams;
    assignmentsW = assignmentWeight;
    testsW = testWeight;
    finalExamsW = finalExamWeight;
}

void ItemType::InitializeStudent(int number, std::string firstName, std::string lastName, int id) {
    value = number;
    fName = firstName;
    lName = lastName;
    idN = id;
}

void ItemType::InitializeGrades(int numOfAssignments, int numOfTests, int numOfFinalExams) {
	assignmentsG.resize(numOfAssignments);
	testsG.resize(numOfTests);
	finalExamsG.resize(numOfFinalExams);
}

void ItemType::InitializeAssignments(int assignmentNumber, int grade) {
    assignmentsG[assignmentNumber-1] = grade;
}

void ItemType::InitializeTests(int testNumber, int grade) {
    testsG[testNumber - 1] = grade;
}

void ItemType::InitializeFinalExams(int finalExamNumber, int grade) {
    for (int i = 0; i < numFinalExams; i++) {
        finalExamsG[finalExamNumber - 1] = grade;
    }
}

// pre:  out has been opened.
// post: value has been sent to the stream out.
void ItemType::Print(std::ostream& out) const {
    //out << value << std::endl;
    out << "Student's name: " << fName << " " << lName << std::endl;
    out << "Student's ID: " << idN << std::endl;

    //out << numAssignments << std::endl;
    //out << numTests << std::endl;
    //out << numFinalExams << std::endl;

    //out << assignmentsW << std::endl;
    //out << testsW << std::endl;
    //out << finalExamsW << std::endl;

	for (int i = 0; i < numAssignments; i++) {
		out << "Assignment " << i+1 << " grade: " << assignmentsG[i] << std::endl;
	}

    for (int i = 0; i < numTests; i++) {
        out << "Test " << i + 1 << " grade: " << testsG[i] << std::endl;
    }

    for (int i = 0; i < numFinalExams; i++) {
        out << "Final exam " << i + 1 << " grade: " << finalExamsG[i] << std::endl;
    }
}
