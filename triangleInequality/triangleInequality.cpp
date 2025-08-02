/* 
Explanation of the algorithm:
1. The program checks whether three given side lengths can form a triangle using the triangle inequality theorem.
2. The function `isTrianglePosible`:
   - Takes three integers representing the side lengths of a triangle.
   - Checks the triangle inequality conditions:
     - The sum of any two sides must be greater than the third side.
   - Returns `true` if all conditions are satisfied, otherwise returns `false`.
3. The main function:
   - Calls `isTrianglePosible` with test values and displays whether the sides can form a triangle.
*/

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