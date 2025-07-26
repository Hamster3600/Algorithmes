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