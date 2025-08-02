/* 
Explanation of the algorithm:
1. The program implements the Bubble Sort algorithm to sort an array.
2. The function `bubbleSort`:
   - Iterates through the array multiple times.
   - Compares adjacent elements and swaps them if they are in the wrong order.
   - Repeats the process until the array is fully sorted.
3. The main function:
   - Defines an array and its size.
   - Calls `bubbleSort` to sort the array.
   - Displays the array before and after sorting.
*/

#include <iostream>

void bubbleSort(int tab[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(tab[j] > tab[j+1]){
                int tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
        }
    }
}

int main(){
    int tab[3] = {3,4,2};

    std::cout << "Tablica przed sortowaniem: ";
    for(int i = 0; i < 3; ++i) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    int n = 3;

    bubbleSort(tab, n);

    std::cout << "Tablica po sortowaniu: ";
    for(int i = 0; i < 3; ++i) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}