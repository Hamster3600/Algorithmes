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
