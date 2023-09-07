#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h" 
// File ItemType.h must be provided by the user of this class. 
//  ItemType.h must contain the following definitions: 
//  MAX_ITEMS:     the maximum number of items on the list 
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 
struct NodeType;

class UnsortedType {

public:

  // Constructor
  UnsortedType();

  // Destructor
  ~UnsortedType();

  // Function: Returns the list to the empty state.
  // Post:  List is empty.
  void MakeEmpty();

  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)
  bool IsFull() const;
  
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list
  int GetLength() const;
  
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned;	
  // 	 otherwise found = false and item is returned.
  //       List is unchanged.
  ItemType GetItem(ItemType& item, bool& found);
  
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  //       item is not in list.
  // Post: item is in list.
  void PutItem(ItemType item);
  
  // Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.
  void DeleteItem(ItemType item);
  
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.
  void ResetList();
  
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.
  ItemType GetNextItem();
  
private:
  
  NodeType* listData;
  int length;
  NodeType* currentPos;
};

#endif
