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