/* 
Explanation of the algorithm:
1. The program implements the Merge Sort algorithm to sort an array.
2. The function `merge`:
   - Merges two sorted subarrays into a single sorted array.
3. The function `mergeSort`:
   - Recursively divides the array into two halves.
   - Sorts each half and merges them using the `merge` function.
4. The main function:
   - Defines an array and its size.
   - Calls `mergeSort` to sort the array.
   - Displays the array before and after sorting.
*/

#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        }   else{
            arr[k++] = R[j++];
        }
    }

    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> tab = {1,5,2,6,7,3,2};

    printArray(tab);

    mergeSort(tab, 0, tab.size() - 1);

    printArray(tab);
    return 0;
}