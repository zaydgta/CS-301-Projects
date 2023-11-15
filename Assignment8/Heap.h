/***
Title: <Heap.h>
Author: <Nell Dale, Chip Weems, Tim Richards>
Date: <11/14/2023>
Code version: <Latest>
Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
*
***/

// Assumes ItemType is either a built-in simple type or a class with overloaded relational operators.
template<class ItemType> struct HeapType {
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    ItemType* elements;   // Array to be allocated dynamically
    int numElements;
};

template <class ItemType> void Swap(ItemType& one, ItemType& two){ 
    ItemType temp;
    temp = one;
    one = two;
    two = temp;
}  

template<class ItemType> void HeapType<ItemType>::ReheapUp(int root, int bottom) {
    
    // Post: Heap property is restored.

    int parent;
  
    if (bottom > root) {
        parent = (bottom-1) / 2;
        if (elements[parent] < elements[bottom]) {
            Swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}

template<class ItemType> void HeapType<ItemType>::ReheapDown(int root, int bottom) {
    
    // Post: Heap property is restored.

    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root*2+1;
    rightChild = root*2+2;
    if (leftChild <= bottom) {
        
        if (leftChild == bottom) {
            maxChild = leftChild;
        } else {
            if (elements[leftChild] <= elements[rightChild]) {
                maxChild = rightChild;
            } else {
                maxChild = leftChild;
            }
        }
        
        if (elements[root] < elements[maxChild]) {
            Swap(elements[root], elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }
}