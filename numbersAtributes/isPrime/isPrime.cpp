/* 
Explanation of the algorithm:
1. The program checks whether a given number is a prime number.
2. The function `isPrime`:
   - Returns `false` for numbers less than or equal to 1.
   - Iterates through all integers from 2 to the square root of the number.
   - Checks if the number is divisible by any of these integers.
   - Returns `true` if no divisors are found, otherwise returns `false`.
3. The main function:
   - Prompts the user to input a number.
   - Calls `isPrime` to check if the number is prime.
   - Outputs the result.
*/

#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    std::cout << "Give number: ";
    std::cin >> num;

    if (isPrime(num)) {
        std::cout << num << " is prime number" << std::endl;
    } else {
        std::cout << num << " isn't prime number" << std::endl;
    }

    return 0;
}