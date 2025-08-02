/* 
Explanation of the algorithm:
1. The program performs prime factorization of a given number.
2. The main function:
   - Prompts the user to input a number.
   - Iterates through all integers starting from 2 up to the number.
   - For each integer, checks if it divides the number without a remainder.
   - Divides the number by the integer repeatedly until it is no longer divisible.
   - Prints each prime factor as it is found.
*/

#include <iostream>

int main() {
    int num;
    std::cout << "Give number: ";
    std::cin >> num;

    for (int i = 2; i <= num; i++) {
        while (num % i == 0) {
            std::cout << i << std::endl;
            num /= i;
        }
    }

    return 0;
}
