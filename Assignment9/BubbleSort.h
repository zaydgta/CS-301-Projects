/***
Title: <BubbleSort.h>
Author: <Nell Dale, Chip Weems, Tim Richards>
Date: <11/30/2023>
Code version: <Latest>
Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
*
***/

// Post: Adjacent pairs that are out of order have been switched between values[startIndex]..values[endIndex] beginning at values[endIndex].
template<class ItemType> void BubbleUp(ItemType values[], int startIndex, int endIndex){
    for (int index = endIndex; index > startIndex; index--) {
        if (values[index] < values[index - 1]) {
            Swap(values[index], values[index - 1]);
        }
    }
}

// Post: The elements in the array values are sorted by key.
template<class ItemType> void BubbleSort(ItemType values[], int numValues){
  
    int current = 0;

    while (current < numValues - 1){
        BubbleUp(values, current, numValues-1);
        current++;
    }
}