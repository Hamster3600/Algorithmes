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