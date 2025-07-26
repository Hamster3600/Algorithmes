#include <iostream>
#include <vector>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high; j++){
        if(arr[j] <= pivot){
            i++;    
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return(i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> arr = {10, 7, 8 , 9, 1, 5};
    int n = arr.size();
    
    std::cout << "Oryginalny arr: ";
    printArray(arr);

    quickSort(arr, 0, n-1);
    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}