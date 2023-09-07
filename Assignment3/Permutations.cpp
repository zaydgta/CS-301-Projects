#include "Permutations.h"

// Constructor
Permutations::Permutations(int n): setSize(n), permutation(n), direction(n, -1) {
    
    InitializeSet();
}

// Destructor
Permutations::~Permutations() {}

// Initializes the permutation vector with amount of numbers declared
void Permutations::InitializeSet() {
    for (int i = 0; i < setSize; ++i) {
        permutation[i] = i + 1;
    }
}

// Finds the biggest mobile element in the permutations vector
bool Permutations::FindMobileElement(int& mobileIndex) {
    
    // Variables
    mobileIndex = -1;
    int mobile = -1;

    // Finds the mobile element
    for (int i = 0; i < setSize; ++i) {
        int nextIndex = i + direction[i];
        if (nextIndex >= 0 && nextIndex < setSize && permutation[i] > permutation[nextIndex]) {
            if (permutation[i] > mobile) {
                mobile = permutation[i];
                mobileIndex = i;
            }
        }
    }

    // Returns true or false if mobile element is found
    return (mobileIndex != -1);
}

// Swaps the two integers
void Permutations::Swap(int index1, int index2) {
    swap(permutation[index1], permutation[index2]);
    swap(direction[index1], direction[index2]);
}

// Reverses the directions of the specified element
void Permutations::ReverseDirections(int k) {
    for (int i = 0; i < setSize; ++i) {
        if (permutation[i] > k) {
            direction[i] = -direction[i];
        }
    }
}

// Generates all the permutations then prints them out
void Permutations::GeneratePermutations() {
    
    // Variables
    int count = 1;
    int mobileIndex;
    int factorial = getFactorial(setSize);

    // Prints out number of permutations
    cout << "There are " << factorial << " permutations of the set {";
    for (int i = 0; i < setSize; ++i) {
        cout << (i + 1);
        if (i < setSize - 1) {
            cout << ", ";
        }
    }
    cout << "}:" << endl;

    // Prints out all the possbile permutations
    while (count <= factorial) {
        cout << setw(4) << count << ": ";
        PrintPermutations();
        count++;

        if (!FindMobileElement(mobileIndex)) {
            break;
        }

        int k = permutation[mobileIndex];
        int nextIndex = mobileIndex + direction[mobileIndex];
        Swap(mobileIndex, nextIndex);
        ReverseDirections(k);
    }
}

// Prints the permutations
void Permutations::PrintPermutations() {
    for (int i = 0; i < setSize; ++i) {
        cout << permutation[i] << " ";
    }
    cout << endl;
}

// Finds the number of permutations
int Permutations::getFactorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * getFactorial(n - 1);
    }
}
