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