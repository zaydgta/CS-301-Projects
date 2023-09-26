#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

const int PROG_GRADE_SIZE = 6;
const int TEST_GRADE_SIZE = 4;

struct students {

    //Basic student info
    string firstName;
    string lastName;
    int id;

    //Weights of assignment (must = 100%)
    int assignmentWeight;
    int testWeight;
    int finalExamWeight;

    //Grades of all assignments
    float programmingGrade[PROG_GRADE_SIZE];
    float testGrade[TEST_GRADE_SIZE];
    float finalExamGrade;
    float finalGrade;

	// Creates new semester
	void createSemester();

	// Creates new student
	void createStudent();

	// Records assignments
	void recordAssignment();

	// Records tests
	void recordTest();

	// Records final exam
	void recordFinalExam();

	// Changes the grade
	void changeGrade();

	// Calculates the final grade
	void calculateFinalGrade();

	// Outputs the grade data into the file Grades.out
	void outputGrade();

	// Saves the grade data into the file Grades.dat by overwriting it
	// or creating a new one if not there then quits the program
	void quit();
};

#endif
