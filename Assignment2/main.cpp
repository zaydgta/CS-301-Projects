#include "Permutations.h"
#include <iostream>
#include <iomanip>

Permutations::Permutations(int n) : setSize(n), permutation(n), direction(n, -1) {
    InitializeSet();
}

Permutations::~Permutations() {}

void Permutations::InitializeSet() {
    for (int i = 0; i < setSize; ++i) {
        permutation[i] = i + 1;
    }
}

bool Permutations::FindMobileElement(int& mobileIndex) {
    mobileIndex = -1;
    int mobile = -1;

    for (int i = 0; i < setSize; ++i) {
        int nextIndex = i + direction[i];
        if (nextIndex >= 0 && nextIndex < setSize && permutation[i] > permutation[nextIndex]) {
            if (permutation[i] > mobile) {
                mobile = permutation[i];
                mobileIndex = i;
            }
        }
    }

    return (mobileIndex != -1);
}

void Permutations::Swap(int index1, int index2) {
    std::swap(permutation[index1], permutation[index2]);
    std::swap(direction[index1], direction[index2]);
}

void Permutations::ReverseDirections(int k) {
    for (int i = 0; i < setSize; ++i) {
        if (permutation[i] > k) {
            direction[i] = -direction[i];
        }
    }
}

void Permutations::GeneratePermutations() {
    int count = 1;
    int mobileIndex;

    int factorial = getFactorial(setSize);

    std::cout << "There are " << factorial << " permutations of the set {";
    for (int i = 0; i < setSize; ++i) {
        std::cout << (i + 1);
        if (i < setSize - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}:" << std::endl;

    while (count <= factorial) {
        std::cout << std::setw(4) << count << ": ";
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

void Permutations::PrintPermutations() {
    for (int i = 0; i < setSize; ++i) {
        std::cout << permutation[i] << " ";
    }
    std::cout << std::endl;
}

int Permutations::getFactorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * getFactorial(n - 1);
    }
}



int main() {
    int n;

    std::cout << "Enter n (1 <= n <= 25): ";
    std::cin >> n;

    if (n < 1 || n > 25) {
        std::cout << "Invalid input. n must be between 1 and 25." << std::endl;
        return 1;
    }

    Permutations p(n);
    p.GeneratePermutations();

    return 0;
}
