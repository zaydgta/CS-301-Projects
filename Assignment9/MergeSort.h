/***
Title: <MergeSort.h>
Author: <Nell Dale, Chip Weems, Tim Richards>
Date: <11/30/2023>
Code version: <Latest>
Availability: <https://www.jblearning.com/catalog/productdetails/9781284089189>
*
***/

// Post: values[leftFirst]..values[leftLast] and values[rightFirst]..values[rightLast] have been merged. 
// values[leftFirst]..values[rightLast] is now sorted.
template<class ItemType> void Merge (ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast){
    ItemType tempArray[SIZE];
    int index = leftFirst;
    int saveFirst = leftFirst;
  
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)){
        if (values[leftFirst] < values[rightFirst]){
            tempArray[index] = values[leftFirst];
            leftFirst++;
        } else {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }

    index++;
    }

    // Copy remaining items from left half.
    while (leftFirst <= leftLast){
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }

    // Copy remaining items from right half.
    while (rightFirst <= rightLast){
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }

    for (index = saveFirst; index <= rightLast; index++) {
        values[index] = tempArray[index];
    }
}

// Post: The elements in values are sorted by key.
template<class ItemType> void MergeSort(ItemType values[], int first, int last){
    if (first < last){
        int middle = (first + last) / 2;
        MergeSort(values, first, middle);
        MergeSort(values, middle + 1, last);
        Merge(values, first, middle, middle + 1, last);
    }
}