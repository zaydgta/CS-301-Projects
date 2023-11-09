/***
 Title: <TreeType.cpp>
 Author: <Nell Dale, Chip Weems, Tim Richards>
 Date: <11/8/2023>
 Code version: <Latest>
 Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
 *
 ***/

#include "TreeType.h"
struct TreeNode {
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

// Function prototypes
int CountNodes(TreeNode* tree);
void Retrieve(TreeNode* tree, ItemType& item, bool& found);
void Insert(TreeNode*& tree, ItemType item);
void DeleteNode(TreeNode*& tree);
void Delete(TreeNode*& tree, ItemType item);
void GetPredecessor(TreeNode* tree, ItemType& data);
void Destroy(TreeNode*& tree);
void CopyTree(TreeNode*& copy, const TreeNode* originalTree);
void PreOrder(TreeNode*, QueType&);     // Enqueues tree items in preorder.
void InOrder(TreeNode*, QueType&);      // Enqueues tree items in inorder.
void PostOrder(TreeNode*, QueType&);    // Enqueues tree items in postorder.

// Returns true if there is no room for another item on the free store; false otherwise.
bool TreeType::IsFull() const {

    TreeNode* location;

    try {
        location = new TreeNode;
        delete location;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    }
}

// Returns true if the tree is empty; false otherwise.
bool TreeType::IsEmpty() const {
    return root == NULL;
}

// Calls recursive function CountNodes to count the nodes in the tree.
int TreeType::GetLength() const {
    return CountNodes(root);
}

int CountNodes(TreeNode* tree) {
    // Post: returns the number of nodes in the tree.

    if (tree == NULL) {
        return 0;
    } else {
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
    }
}

// Calls recursive function Retrieve to search the tree for item.
ItemType TreeType::GetItem(ItemType item, bool& found) {
    Retrieve(root, item, found);
    return item;
}

// Recursively searches tree for item.
void Retrieve(TreeNode* tree, ItemType& item, bool& found) {

    // Post: If there is an element someItem whose key matches item's,
    //       found is true and item is set to a copy of someItem; 
    //       otherwise found is false and item is unchanged.

    if (tree == NULL) {
        found = false;                      // item is not found.
    } else if (item < tree->info) {
        Retrieve(tree->left, item, found);  // Search left subtree.
    } else if (item > tree->info) {
        Retrieve(tree->right, item, found); // Search right subtree.
    } else {
        item = tree->info;                  // item is found.
        found = true;
    }
} 

// Calls recursive function Insert to insert item into tree.
void TreeType::PutItem(ItemType item) {
    Insert(root, item);
}

// Inserts item into tree.
void Insert(TreeNode*& tree, ItemType item) {

    // Post:  item is in tree; search property is maintained.

    // Insertion place found.
    if (tree == NULL){
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    } else if (item < tree->info){
        Insert(tree->left, item);    // Insert in left subtree.
    } else {
        Insert(tree->right, item);   // Insert in right subtree.
    } 
}

// Calls recursive function Delete to delete item from tree.
void TreeType::DeleteItem(ItemType item) {
    Delete(root, item);
}

// Deletes item from tree.
void Delete(TreeNode*& tree, ItemType item) {
// Post:  item is not in tree.

    if (item < tree->info) {
        Delete(tree->left, item);   // Look in left subtree.
    } else if (item > tree->info) {
        Delete(tree->right, item);  // Look in right subtree.
    } else {
        DeleteNode(tree);           // Node found; call DeleteNode.
    }
}   

// Deletes the node pointed to by tree.
void DeleteNode(TreeNode*& tree) {
    // Post: The user's data in the node pointed to by tree is no 
    //       longer in the tree.  If tree is a leaf node or has only 
    //       non-NULL child pointer the node pointed to by tree is 
    //       deleted; otherwise, the user's data is replaced by its 
    //       logical predecessor and the predecessor's node is deleted.

    ItemType data;
    TreeNode* tempPtr;

    tempPtr = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
    } else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
    } else {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);  // Delete predecessor node.
    }
}

// Sets data to the info member of the right-most node in tree.
void GetPredecessor(TreeNode* tree, ItemType& data){
    while (tree->right != NULL) {
        tree = tree->right;
    }
    data = tree->info;
}

// Prints info member of items in tree in sorted order on outFile.
void PrintTree(TreeNode* tree, std::ofstream& outFile) {
  
    if (tree != NULL) {
        PrintTree(tree->left, outFile);   // Print left subtree.
        outFile << tree->info;
        PrintTree(tree->right, outFile);  // Print right subtree.
    }
}

// Calls recursive function Print to print items in the tree.
void TreeType::Print(std::ofstream& outFile) const {
    PrintTree(root, outFile);
}

TreeType::TreeType() {
    root = NULL;
}

// Calls recursive function Destroy to destroy the tree.
TreeType::~TreeType() {
    Destroy(root);
}

void Destroy(TreeNode*& tree) {
    // Post: tree is empty; nodes have been deallocated.

    if (tree != NULL) {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

void TreeType::MakeEmpty() {

     Destroy(root);
    root = NULL;
}

// Calls recursive function CopyTree to copy originalTree into root.
TreeType::TreeType(const TreeType& originalTree) {
    CopyTree(root, originalTree.root);
}

// Calls recursive function CopyTree to copy originalTree into root.
void TreeType::operator=(const TreeType& originalTree) {
    
    if (&originalTree == this) {
        return;             // Ignore assigning self to self
    }
    Destroy(root);          // Deallocate existing tree nodes
    CopyTree(root, originalTree.root);
}

void CopyTree(TreeNode*& copy, const TreeNode* originalTree) {
    // Post: copy is the root of a tree that is a duplicate 
    //       of originalTree.
    if (originalTree == NULL) {
        copy = NULL;
    } else {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

// Calls function to create a queue of the tree elements in the desired order.
void TreeType::ResetTree(OrderType order) {
  
    switch (order) {
        case PRE_ORDER : PreOrder(root, preQue);
            break;
        case IN_ORDER  : InOrder(root, inQue);
            break;
        case POST_ORDER: PostOrder(root, postQue);
            break;
    }
}

void PreOrder(TreeNode* tree, QueType& preQue) {
    // Post: preQue contains the tree items in preorder.

    if (tree != NULL) {
        preQue.Enqueue(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}

void InOrder(TreeNode* tree, QueType& inQue) {
    // Post: inQue contains the tree items in inorder.

    if (tree != NULL) {
        InOrder(tree->left, inQue);
        inQue.Enqueue(tree->info);
        InOrder(tree->right, inQue);
    }
}

void PostOrder(TreeNode* tree, QueType& postQue) {
    // Post: postQue contains the tree items in postorder.

    if (tree != NULL) {
        PostOrder(tree->left, postQue);
        PostOrder(tree->right, postQue);
        postQue.Enqueue(tree->info);
    }
}

// Returns the next item in the desired order.
ItemType TreeType::GetNextItem(OrderType order, bool& finished) {
    // Post: For the desired order, item is the next item in the queue.
    //       If item is the last one in the queue, finished is true; 
    //       otherwise finished is false.
  
    finished = false;
    ItemType item;
    switch (order) {
        case PRE_ORDER  : preQue.Dequeue(item);
            if (preQue.IsEmpty())
                finished = true;
            break;
        case IN_ORDER   : inQue.Dequeue(item);
            if (inQue.IsEmpty())
                finished = true;
            break;
        case  POST_ORDER: postQue.Dequeue(item);
            if (postQue.IsEmpty())
                finished = true;
            break;
    }
    return item;
}