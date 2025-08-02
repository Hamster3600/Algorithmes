/* 
Explanation of the algorithm:
1. The program finds the most frequent element in an array.
2. The function `findMostFrequent`:
   - Initializes a frequency array to count occurrences of each element.
   - Iterates through the input array, updating the frequency array.
   - Finds the element with the highest frequency and returns it.
3. The main function:
   - Defines an array of integers.
   - Calls `findMostFrequent` to compute and display the most frequent element.
*/

#include <iostream>

int findMostFrequent(int arr[], int size, int max_val_inclusive) {
    if (size <= 0) {
        return -1;
    }

    int counts[100] = {0};

    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0 && arr[i] <= max_val_inclusive && arr[i] < 100) {
            counts[arr[i]]++;
        }
    }

    int mostFrequentElement = arr[0];
    int maxCount = 0;

    for (int i = 0; i <= max_val_inclusive && i < 100; ++i) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            mostFrequentElement = i;
        }
    }

    return mostFrequentElement;
}

int main() {
    int numbers1[] = {1, 3, 2, 1, 3, 3, 5, 1};
    int size1 = sizeof(numbers1) / sizeof(numbers1[0]);
    std::cout << "Najczestszy element w numbers1: " << findMostFrequent(numbers1, size1, 5) << std::endl;
    return 0;
}