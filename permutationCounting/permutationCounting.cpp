/* 
Explanation of the algorithm:
1. The program generates all permutations of a given set of elements and calculates the total number of permutations.
2. The function `generatePermutations`:
   - Recursively swaps elements to generate permutations.
   - Stops when the permutation size equals the size of the set and prints the permutation.
3. The function `factorial`:
   - Calculates the factorial of a number to determine the total number of permutations.
4. The main function:
   - Defines a set of elements.
   - Calls `generatePermutations` to generate and display all permutations.
   - Calls `factorial` to compute and display the total number of permutations.
*/

#include <iostream>
#include <vector>
#include <string>

void swapElements(std::vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void generatePermutations(std::vector<int> arr, int k) {
    if (k == arr.size()) {
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = k; i < arr.size(); i++) {
        swapElements(arr, k, i);
        generatePermutations(arr, k + 1);
        swapElements(arr, k, i);
    }
}

long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    std::vector<int> numbers = {1, 2, 3};
    generatePermutations(numbers, 0);
    std::cout << "Number of permutations for 3 elements: " << factorial(3) << std::endl;
    return 0;
}