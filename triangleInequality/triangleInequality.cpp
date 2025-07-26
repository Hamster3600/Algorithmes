#include <iostream>

bool isTrianglePosible(int a, int b, int c){
    if(a + b <= c){
        return 0;
    }   else if(a + c <= b){
        return 0;
    }   else if(b + c <= a){
        return 0;
    }
    return 1;
}

int main(){
    std::cout << isTrianglePosible(5, 3, 5);
    return 0;
}