/* 
Explanation of the algorithm:
1. The program calculates the Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of two numbers.
2. The function `gcd`:
   - Implements the Euclidean algorithm to find the GCD.
   - Iteratively replaces the larger number with its remainder when divided by the smaller number.
3. The function `lcm`:
   - Calculates the LCM using the formula: `LCM = (a * b) / GCD`.
4. The main function:
   - Prompts the user to input two numbers.
   - Handles negative inputs by converting them to positive.
   - Calls `gcd` and `lcm` to compute and display the results.
*/

#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;

    if (num1 == 0 && num2 == 0) {
        std::cout << "GCD and LCM are undefined for two zeros." << std::endl;
    } else if (num1 == 0 || num2 == 0) {
        std::cout << "GCD(" << num1 << ", " << num2 << ") = " << (num1 == 0 ? num2 : num1) << std::endl;
        std::cout << "LCM(" << num1 << ", " << num2 << ") = 0" << std::endl;
    } else {
        int result_gcd = gcd(num1, num2);
        int result_lcm = lcm(num1, num2);

        std::cout << "GCD of " << num1 << " and " << num2 << " is: " << result_gcd << std::endl;
        std::cout << "LCM of " << num1 << " and " << num2 << " is: " << result_lcm << std::endl;
    }

    return 0;
}