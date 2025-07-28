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