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