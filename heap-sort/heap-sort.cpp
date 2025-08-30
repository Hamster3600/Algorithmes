/*
Explanation of the program:
1. The program implements the Heap Sort algorithm.
2. swap:
   - Swaps two values in an array.
3. heapify:
   - Restores the heap property on a subtree.
   - Compares a node with its children and moves the largest element upwards.
4. heapSort:
   - Divides the sorting into two main stages.
   - In the first stage, it builds a max-heap from the array.
   - In the second stage, it repeatedly swaps the root with the last element and restores the heap property until the entire array is sorted.
5. writeArray:
   - Prints the contents of the array.
6. main:
   - Demonstrates the use of the heapSort function on an unsorted array.
*/

#include <iostream>

void swap(int t[], int a, int b) {
    int temp = t[a];
    t[a] = t[b];
    t[b] = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    std::cout << "Array after building the heap: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}

void writeArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {2, 10, 4, 7, 1, 8, 9, 3, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array before sorting: ";
    writeArray(arr, n);

    heapSort(arr, n);

    std::cout << "Array after sorting: ";
    writeArray(arr, n);

    return 0;
}