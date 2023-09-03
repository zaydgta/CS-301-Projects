#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include <string>
#include <vector>
#include <fstream>

class Permutations {
public:
    Permutations(int n);
    ~Permutations();

    void GeneratePermutations();
    void PrintPermutations();
    int getFactorial(int n);

private:
    int setSize;
    std::vector<int> permutation;
    std::vector<int> direction;

    bool FindMobileElement(int& mobileIndex);
    void Swap(int index1, int index2);
    void ReverseDirections(int k);
    void InitializeSet();
};

#endif // PERMUTATIONS_H
