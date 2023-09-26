// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include "ItemType.h"


ItemType::ItemType() { 
    value = 0;
    firstName = " ";
    lastName = " ";
    id = 0;
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
    firstName = firstName;
    lastName = lastName;
    id = id;
}

// pre:  out has been opened.
// post: value has been sent to the stream out.
void ItemType::Print(std::ostream& out) const {
    out << value << std::endl;
    out << firstName << std::endl;
    out << lastName << std::endl;
    out << id << std::endl;
}
