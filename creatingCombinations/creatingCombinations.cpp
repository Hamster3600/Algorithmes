#include <iostream>
#include <vector>

void generateCombinations(const std::vector<int>& set, int k, int startIdx, std::vector<int>& currentCombination) {
    if (currentCombination.size() == k) {
        std::cout << "{ ";
        for (int i = 0; i < currentCombination.size(); i++) {
            std::cout << currentCombination[i] << " ";
        }
        std::cout << "}" << std::endl;
        return;
    }

    for (int i = startIdx; i < set.size(); i++) {
        currentCombination.push_back(set[i]);
        generateCombinations(set, k, i + 1, currentCombination);
        currentCombination.pop_back();
    }
}

int main() {
    std::vector<int> mySet = {1, 2, 3, 4};
    int k = 2;
    std::vector<int> currentCombination;
    generateCombinations(mySet, k, 0, currentCombination);
    return 0;
}