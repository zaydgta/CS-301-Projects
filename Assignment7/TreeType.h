/***
 Title: <TreeType.h>
 Author: <Nell Dale, Chip Weems, Tim Richards>
 Date: <11/8/2023>
 Code version: <Latest>
 Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
 *
 ***/

#include <string>
#include <fstream>
typedef char ItemType;
struct TreeNode;
#include "QueType.h"

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType {
public:
  
	TreeType();									// constructor
	~TreeType();								// destructor
	TreeType(const TreeType& originalTree);		// copy constructor
	void operator=(const TreeType& originalTree);
	
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int GetLength() const; 
	ItemType GetItem(ItemType item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetTree(OrderType order); 
	ItemType GetNextItem(OrderType order, bool& finished);
	void Print(std::ofstream& outFile) const;

private:
	
	TreeNode* root;
	QueType preQue;
	QueType inQue;
	QueType postQue;
};

