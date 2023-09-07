#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class Permutations {

private:

    // Variables
    int setSize;
    vector<int> permutation;
    vector<int> direction;

    // Finds the biggest mobile element in the permutations vector
    bool FindMobileElement(int& mobileIndex);

    // Swaps the two integers
    void Swap(int index1, int index2);

    // Reverses the directions of the specified element
    void ReverseDirections(int k);

    // Initializes the permutation vector with amount of numbers declared
    void InitializeSet();

public:

    // Constructor
    Permutations(int n);

    // Destructor
    ~Permutations();

    // Generates all the permutations then prints them out
    void GeneratePermutations();

    // Prints the permutations
    void PrintPermutations();

    // Finds the number of permutations
    int getFactorial(int n);

};

#endif
