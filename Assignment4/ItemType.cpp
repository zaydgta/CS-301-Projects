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

void ItemType::InitializeSemester(int numOfAssignments, int numOfTests, int numOfFinalExams, int assignmnetWeight, int testWeight, int finalExamWeight) {
    numAssignments = numOfAssignments;
    numTests = numOfTests;
    numFinalExams = numOfFinalExams;
    assignmentsW = assignmnetWeight;
    testsW = testWeight;
    finalExamsW = finalExamWeight;
}

void ItemType::InitializeStudent(int number, std::string firstName, std::string lastName, int id) {
    value = number;
    fName = firstName;
    lName = lastName;
    idN = id;
}

void ItemType::InitializeAssignments(int assignmentNumber, int grade) {
    assignmentsG[assignmentNumber] = grade;
}

void ItemType::InitializeTests(int tests[]) {
    for (int i = 0; i < numTests; i++) {
        testsG[i] = tests[i];
    }
}

void ItemType::InitializeFinalExams(int finalExams[]) {
    for (int i = 0; i < numFinalExams; i++) {
        finalExamsG[i] = finalExams[i];
    }
}

// pre:  out has been opened.
// post: value has been sent to the stream out.
void ItemType::Print(std::ostream& out) const {
    out << value << std::endl;
    out << fName << std::endl;
    out << lName << std::endl;
    out << idN << std::endl;

    out << numAssignments << std::endl;
    out << numTests << std::endl;
    out << numFinalExams << std::endl;

    out << assignmentsW << std::endl;
    out << testsW << std::endl;
    out << finalExamsW << std::endl;

}
