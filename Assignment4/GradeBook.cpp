#include "GradeBook.h"
using namespace std;

struct NodeType {

    ItemType info;
    NodeType* next;
};

// Class constructor
GradeBook::GradeBook() {

    length = 0;
    listData = NULL;
}

bool GradeBook::IsFull() const {
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch(std::bad_alloc exception) {
        return true;
    }
}

int GradeBook::GetLength() const {
    return length;
}

void GradeBook::MakeEmpty() {
    NodeType* tempPtr;

    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }

    length = 0;
}

ItemType GradeBook::GetItem(ItemType& item, bool& found) {

    bool moreToSearch;
    NodeType* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found) {
        switch(item.ComparedToName(location->info)) {
            case GREATER:
                location = location->next;
                moreToSearch = (location != NULL);
                break;

            case EQUAL:
                found = true;
                item = location->info;
                break;

            case LESS:
                moreToSearch = false;
                break;
        }
    }

  return item;
}

void GradeBook::DeleteItem(ItemType item) {
    NodeType* location = listData;
    NodeType* tempLocation;

    // Locate node to be deleted.
    if (item.ComparedToName(listData->info) == EQUAL) {
        tempLocation = location;
        listData = listData->next;	// Delete first node.
    } else {

        while (item.ComparedToName((location->next)->info) != EQUAL) {
            location = location->next;
        }

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

void GradeBook::ResetList() {
    currentPos = NULL;
}

ItemType GradeBook::GetNextItem() {

    ItemType item;
    if (currentPos == NULL) {
        currentPos = listData;
    }

    item = currentPos->info;
    currentPos = currentPos->next;
    return item;
}

GradeBook::~GradeBook(){

    NodeType* tempPtr;

    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

// Creates new student
void GradeBook::createStudent(ItemType item){

    NodeType* newNode;  	// pointer to node being inserted
    NodeType* predLoc;  	// trailing pointer
    NodeType* location; 	// traveling pointer
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);

    // Find insertion point.
    while (moreToSearch) {
        switch(item.ComparedToName(location->info)) {
            case GREATER:
                predLoc = location;
      	        location = location->next;
                moreToSearch = (location != NULL);
                break;

            case LESS:
                moreToSearch = false;
                break;
        }
    }

    // Prepare node for insertion
    newNode = new NodeType;
    newNode->info = item;

    // Insert node into list
    // Insert as first
    if (predLoc == NULL){
        newNode->next = listData;
        listData = newNode;
    } else {
        newNode->next = location;
        predLoc->next = newNode;
    }

  length++;
}

// Records the grades for the assignments for student
void GradeBook::recordAssignment(int number) {
    
    int length = GetLength();
    int grade;
    bool found;

    ResetList();

    cout << "You have chosen assignment number " << number << "." << endl;

    for (int counter = 0; counter < length; counter++) {

        ItemType item;
        item = GetNextItem();

        cout << "Please enter the assignment's grade for the student " << item.fName << " " << item.lName << endl;
        cin >> grade;

        item.InitializeAssignments(number, grade);
        modifyStudent(item, found);
    }
};

// Modifies the data for the student in the grade book
void GradeBook::modifyStudent(ItemType& item, bool& found) {
    
    NodeType* newNode;  	// pointer to node being inserted
    NodeType* predLoc;  	// trailing pointer
    NodeType* location; 	// traveling pointer
    
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);
    found = false;
 
    // Finds the desired node in the list
    while (moreToSearch && !found) {
        switch (item.ComparedToName(location->info)) {
        case GREATER:
            location = location->next;
            moreToSearch = (location != NULL);
            break;

        case EQUAL:
            found = true;
            break;

        case LESS:
            moreToSearch = false;
            break;
        }
    }

    // Prepare node for insertion
    newNode = new NodeType;
    newNode->info = item;

    // Insert node into list
    // Insert as first
    if (predLoc == NULL) {
        newNode->next = listData;
        listData = newNode;
    } else {
        newNode->next = location;
        predLoc->next = newNode;
    }
}

// Records the grades for the tests for student
void GradeBook::recordTest(int number) {

    int length = GetLength();
    int grade;
    bool found;

    ResetList();

    cout << "You have chosen test number " << number << "." << endl;

    for (int counter = 0; counter < length; counter++) {

        ItemType item;
        item = GetNextItem();

        cout << "Please enter the test's grade for the student " << item.fName << " " << item.lName << endl;
        cin >> grade;

        item.InitializeTests(number, grade);
        modifyStudent(item, found);
    }
}

void GradeBook::recordFinalExam(int number) {

    int length = GetLength();
    int grade;
    bool found;

    ResetList();

    for (int counter = 0; counter < length; counter++) {

        ItemType item;
        item = GetNextItem();

        cout << "Please enter the final exam grade for the student " << item.fName << " " << item.lName << endl;
        cin >> grade;

        item.InitializeFinalExams(number, grade);
        modifyStudent(item, found);
    }
}

void GradeBook::changeGrade(int id, int grade, char choice) {

    int length = GetLength();
    bool found;
    int number;

    ResetList();

    ItemType item;
    item.idN = id;

    bool moreToSearch;
    NodeType* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found) {
        switch (item.ComparedToID(location->info)) {
        case GREATER:
            location = location->next;
            moreToSearch = (location != NULL);
            break;

        case EQUAL:
            found = true;
            item = location->info;
            break;

        case LESS:
            moreToSearch = false;
            break;
        }
    }

    if (choice == 'P') {
        
        cout << "Which programming assignment number's grade would you like to change?" << endl;
        cin >> number;

        item.InitializeAssignments(number, grade);
        modifyStudent(item, found);
    } else if (choice == 'T') {
       
        cout << "Which test number's grade would you like to change?" << endl;
        cin >> number;

        item.InitializeTests(number, grade);
        modifyStudent(item, found);
    } else if (choice == 'F') {
        
        number = 1;
        item.InitializeFinalExams(number, grade);
        modifyStudent(item, found);
    }
}

void GradeBook::calculateFinalGrade() {
    
    bool found;
    ItemType item;

    ResetList();

    for (int counter = 0; counter < length; counter++) {

        ItemType item;
        item = GetNextItem();

        item.InitializeFinalGrades();
        modifyStudent(item, found);
    }
}