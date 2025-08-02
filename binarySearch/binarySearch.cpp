/* 
Explanation of the algorithm:
1. The program implements the binary search algorithm to find a target element in a sorted array.
2. The function `binarySearch`:
   - Takes a sorted array and a target value as input.
   - Uses two pointers (`low` and `high`) to define the search range.
   - Calculates the middle index (`mid`) and compares the value at `mid` with the target.
   - Adjusts the search range based on whether the target is smaller or larger than the value at `mid`.
   - Returns the index of the target if found, or -1 if not found.
3. The main function:
   - Defines a sorted array and a target value.
   - Calls `binarySearch` and prints the result.
*/

#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int target = 50;
    int index = binarySearch(numbers, target);
    if (index != -1) {
        std::cout << "Element " << target << " found at index: " << index << std::endl;
    } else {
        std::cout << "Element " << target << " not found." << std::endl;
    }

    return 0;
}