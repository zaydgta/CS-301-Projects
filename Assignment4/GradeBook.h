#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "ItemType.h"
// Header file for GradeBook which is a linked list ADT.  
struct NodeType;

class SortedType {

public:
  
	// Class constructor
	SortedType();     

	// Class destructor
	~SortedType();

	// Old functions
	bool IsFull() const;
	int GetLength() const;
	void MakeEmpty();
	ItemType GetItem(ItemType& item, bool& found);
	void PutItem(ItemType item); 
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();

/*
	// New functions TEMPORARY

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
	void finalGrade();	

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
