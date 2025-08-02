/* 
Explanation of the algorithm:
1. The program generates all possible combinations of a given set of elements.
2. The function `generateCombinations`:
   - Takes a set of elements, the desired combination size (`k`), the starting index, and a temporary combination vector.
   - Recursively builds combinations by adding elements to the current combination.
   - Stops when the combination size equals `k` and prints the combination.
3. The main function:
   - Defines a set of elements and the desired combination size.
   - Calls `generateCombinations` to generate and display all combinations.
*/

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