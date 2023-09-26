#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "ItemType.h"
// Header file for GradeBook which is a linked list ADT.
struct NodeType;

class GradeBook {

public:

	// Class constructor
	GradeBook();

	// Class destructor
	~GradeBook();

	// Old functions
	bool IsFull() const;
	int GetLength() const;
	void MakeEmpty();
	ItemType GetItem(ItemType& item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();


	// New functions TEMPORARY

	// Creates new semester
	void createStudent(ItemType item);
/*
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

*/
private:

	NodeType* listData;
	int length;
	NodeType* currentPos;
};

#endif
