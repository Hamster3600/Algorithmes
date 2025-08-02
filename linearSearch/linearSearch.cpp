/* 
Explanation of the algorithm:
1. The program implements a linear search algorithm to find a target element in an array.
2. The function `ifFound`:
   - Takes a vector, a target number, and the size of the vector as input.
   - Appends the target number to the vector to ensure it is always found.
   - Iterates through the vector until the target is found.
   - Prints the index of the target and returns `true`.
3. The main function:
   - Defines a vector and a target number.
   - Calls `ifFound` and prints the result.
*/

#include <iostream>
#include <vector>

bool ifFound(std::vector<int> vec, int num, int n){
    vec.push_back(num);
    int i = 0;
    while(true){
        if(vec[i] == num){
            std::cout << "The number was found on index: " << i << std::endl;
            return true;
        }
        i++;
    }
    return false;
}

int main(){
    std::vector<int> vector = {1,3,3,3,2};
    int n = vector.size();
    int number = 2;
    ifFound(vector, number, n);
    return 0;
}