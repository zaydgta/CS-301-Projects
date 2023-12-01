/***
Title: <SelectionSort.h>
Author: <Nell Dale, Chip Weems, Tim Richards>
Date: <11/30/2023>
Code version: <Latest>
Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
*
***/

template<class ItemType> void Swap(ItemType& a, ItemType& b) {
    ItemType temp = a;
    a = b;
    b = temp;
}

// Post: Returns the index of the smallest value in values[startIndex]..values[endIndex].
template<class ItemType> int MinIndex(ItemType values[], int startIndex, int endIndex){
    int indexOfMin = startIndex;
    for (int index = startIndex + 1; index <= endIndex; index++) {
        if (values[index] < values[indexOfMin]) {
            indexOfMin = index;
        }
    }
    return indexOfMin;
}

// Post: The elements in the array values are sorted by key.
template<class ItemType> void SelectionSort(ItemType values[], int numValues){
    int endIndex = numValues-1;
    for (int current = 0; current < endIndex; current++) {
        Swap(values[current], values[MinIndex(values, current, endIndex)]);
    }
} 