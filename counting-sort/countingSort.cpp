#include <iostream>
#include <vector>

int Min(const std::vector<int>& arr){
    int minVal = arr[0];
    for(int i = 0; i < arr.size(); i ++){
        if(arr[i] < minVal){
            minVal = arr[i];
        }
    }
    return minVal;
}

int Max(const std::vector<int>& arr){
    int maxVal = arr[0];
    for(int i = 0; i < arr.size(); i ++){
        if(arr[i] > maxVal){
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void countingSort(std::vector<int>& arr){
    if(arr.empty()) return;

    int minVal = Min(arr);
    int maxVal = Max(arr);
    int range = maxVal - minVal + 1;

    std::vector<int> count(range, 0);

    for(int i = 0; i < arr.size(); i++){
        count[arr[i] - minVal]++;
    }

    int index = 0;
    for(int i = 0; i < range; ++i){
        while(count[i]-- > 0){
            arr[index++] = i + minVal;  
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> tab = {1,4,3,1,2,5,2};
    printArray(tab);
    countingSort(tab);
    printArray(tab);
    return 0;
}