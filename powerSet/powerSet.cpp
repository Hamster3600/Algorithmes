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