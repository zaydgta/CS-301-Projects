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
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();

	// New functions TEMPORARY
	// Creates new student
	void createStudent(ItemType item);

	// Records assignments
	void recordAssignment(int number);

	// Modifies the data of the student
	void modifyStudent(ItemType& item, bool& found);

	// Records tests
	void recordTest(int number);

	// Records final exam
	void recordFinalExam(int number);

	// Changes the grade for aan assignment
	void changeGrade(int id, int grade, char choice);

	void calculateFinalGrade();


private:

	NodeType* listData;
	int length;
	NodeType* currentPos;
};

#endif
