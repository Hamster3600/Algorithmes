/* 
Explanation of the algorithm:
1. The program implements the Selection Sort algorithm to sort an array.
2. The function `selectionSort`:
   - Iterates through the array to find the smallest element in the unsorted portion.
   - Swaps the smallest element with the first element of the unsorted portion.
   - Repeats the process until the entire array is sorted.
3. The function `swap`:
   - Swaps two elements in the array.
4. The main function:
   - Defines an array and its size.
   - Calls `selectionSort` to sort the array.
   - Displays the array before and after sorting.
*/

#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int tab[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int smallestElement = i;
        for (int j = i + 1; j < size; j++) {
            if (tab[j] < tab[smallestElement]) {
                smallestElement = j;
            }
        }
        if (smallestElement != i) {
            swap(tab[i], tab[smallestElement]);
        }
    }
}


void printArray(const int tab[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int arr[4] = {3,5,2,1};
    int n = 4;
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}