/* 
Explanation of the algorithm:
1. The program calculates the result of raising a base to an exponent using fast exponentiation.
2. The function `fastPower`:
   - Uses the divide-and-conquer approach to compute the power efficiently.
   - If the exponent is odd, multiplies the result by the base.
   - Squares the base and halves the exponent in each iteration.
   - Continues until the exponent becomes zero.
3. The main function:
   - Prompts the user to input a base and an exponent.
   - Calls `fastPower` and displays the result.
*/

#include <iostream>

int fastPower(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

int main(){
    int exponent = 0;
    int base = 0;

    std::cout << "Give base: ";
    std::cin >> base;

    std::cout << "Give exponent: ";
    std::cin >> exponent;

    std::cout << base << "^" << exponent << " = " << fastPower(base, exponent) << std::endl;

    return 0;
}