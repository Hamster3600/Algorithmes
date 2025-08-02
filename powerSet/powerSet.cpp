/* 
Explanation of the algorithm:
1. The program generates the power set (all subsets) of a given set of elements.
2. The function `generatePowerSet`:
   - Calculates the total number of subsets using the formula `2^n`, where `n` is the size of the set.
   - Iterates through all possible subset indices (from 0 to `2^n - 1`).
   - Uses bitwise operations to determine which elements belong to each subset.
   - Prints each subset.
3. The main function:
   - Defines a set of elements.
   - Calls `generatePowerSet` to compute and display the power set.
*/

#include <iostream>
#include <vector>

long long power(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= base;
    }
    return res;
}

void generatePowerSet(const std::vector<int>& set) {
    int n = set.size();
    long long powerSetSize = power(2, n);

    for (long long i = 0; i < powerSetSize; i++) {
        std::cout << "{ ";
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                std::cout << set[j] << " ";
            }
        }
        std::cout << "}" << std::endl;
    }
}

int main() {
    std::vector<int> mySet = {1, 2, 3};
    generatePowerSet(mySet);
    return 0;
}