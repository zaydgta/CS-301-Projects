// The following declarations and definitions go into file 
// ItemType.h. 

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <fstream>
const int MAX_ITEMS = 5;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType {

public:
	ItemType();
	RelationType ComparedTo(ItemType) const;
	void Print(std::ostream&) const;
	void Initialize(int number);

private:
	int value;
};

#endif