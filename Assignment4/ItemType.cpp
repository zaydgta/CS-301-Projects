// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include "ItemType.h"


ItemType::ItemType() { 
    value = 0;
    fName = " ";
    lName = " ";
    idN = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const {
    if (value < otherItem.value) {
        return LESS;
    } else if (value > otherItem.value) {
        return GREATER;
    } else {
        return EQUAL;
    }
}

void ItemType::Initialize(int number, std::string firstName, std::string lastName, int id) {
    value = number;
    fName = firstName;
    lName = lastName;
    idN = id;
}

// pre:  out has been opened.
// post: value has been sent to the stream out.
void ItemType::Print(std::ostream& out) const {
    out << value << std::endl;
    out << fName << std::endl;
    out << lName << std::endl;
    out << idN << std::endl;
}

//Temp
// pre:  out has been opened.
// post: value has been sent to the stream out.
//void ItemType::printItem(){
  //  std::cout << value << std::endl;
    //std::cout << fName << std::endl;
    //std::cout << lName << std::endl;
    //std::cout << idN << std::endl;
//}