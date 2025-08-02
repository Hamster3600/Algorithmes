/* 
Explanation of the algorithm:
1. The program implements the Sieve of Eratosthenes to find all prime numbers up to a given limit.
2. The function `sieveOfEratosthenes`:
   - Initializes an array to mark numbers as prime or non-prime.
   - Iterates through numbers starting from 2, marking multiples of each number as non-prime.
   - Stops when all multiples of numbers up to the square root of the limit are processed.
3. The main function:
   - Defines the limit for prime number generation.
   - Calls `sieveOfEratosthenes` to compute and display all prime numbers up to the limit.
*/

#include <iostream>
#include <cmath>

// Sieve of Eratosthenes
void sieveOfEratosthenes(int primes[], int limit) {
    for (int i = 2; i <= sqrt(limit); i++) {
        if (primes[i]) {
            for (int j = 2 * i; j <= limit; j += i) {
                primes[j] = 0;
            }
        }
    }
}

int main() {
    int primes[1001] = {1}; 
    primes[0] = primes[1] = 0;

    int limit = 1000;

    for (int i = 2; i <= limit; i++) {
        primes[i] = 1;
    }

    sieveOfEratosthenes(primes, limit);

    // Display prime numbers up to the limit
    for (int i = 2; i <= limit; i++) {
        if (primes[i] == 1) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl << std::endl;

    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    // Goldbach's conjecture (even number = sum of two primes)
    for (int i = 2; i <= number; i++) {
        if (primes[i] && primes[number - i]) {
            std::cout << i << " + " << number - i;
            break;
        }
    }

    return 0;
}
