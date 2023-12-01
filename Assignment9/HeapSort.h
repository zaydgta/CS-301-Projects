/***
Title: <HeapSort.h>
Author: <Nell Dale, Chip Weems, Tim Richards>
Date: <11/30/2023>
Code version: <Latest>
Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
*
***/

// Post: Heap property is restored.
template<class ItemType> void ReheapDown(ItemType elements[], int root, int bottom){
    int maxChild;
    int rightChild;
    int leftChild;

    maxChild = 0;
    leftChild = root*2+1;
    rightChild = root*2+2;

    if (leftChild <= bottom) {
        if (leftChild == bottom) {
            maxChild = leftChild;
        }
    } else {
        if (elements[leftChild] <= elements[rightChild]){
            maxChild = rightChild;
        } else {
            maxChild = leftChild;
        }
    }
    if (elements[root] < elements[maxChild]){
        Swap(elements[root], elements[maxChild]);
        ReheapDown(elements, maxChild, bottom);
    }
}

// Pre:  Struct HeapType is available.
// Post: The elements in the array values are sorted by key.
template<class ItemType> void HeapSort(ItemType values[], int numValues){
  
    int index;

    // Convert the array of values into a heap.
    for (index = numValues / 2 - 1; index >= 0; index--) {
        ReheapDown(values, index, numValues - 1);
    }

    // Sort the array.
    for (index = numValues-1; index >=1; index--) {
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index-1);
    }
}