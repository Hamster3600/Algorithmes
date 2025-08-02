/* 
Explanation of the algorithm:
1. The program implements the Insertion Sort algorithm to sort an array.
2. The function `insertonSort`:
   - Iterates through the array, treating the first part as sorted and the rest as unsorted.
   - Inserts each element from the unsorted part into its correct position in the sorted part.
3. The main function:
   - Defines an array and its size.
   - Calls `insertonSort` to sort the array.
   - Displays the array before and after sorting.
*/

#include <iostream>
#include <vector>

void insertonSort(std::vector<int>& arr){
    int size = arr.size();
    for(int i = 1; i < size; ++i){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> tab = {1,5,2,3,4};
    printArray(tab);
    insertonSort(tab);
    printArray(tab);
    return 0;
}