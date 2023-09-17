#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include "ItemType.h"
// Header file for Sorted List ADT.  
struct NodeType;

class SortedType {

public:
  
	// Class constructor
	SortedType();     

	// Class destructor
	~SortedType();

	bool IsFull() const;
	int GetLength() const;
	void MakeEmpty();
	ItemType GetItem(ItemType& item, bool& found);
	void PutItem(ItemType item); 
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();

private:

	NodeType* listData;
	int length;
	NodeType* currentPos;
};

#endif