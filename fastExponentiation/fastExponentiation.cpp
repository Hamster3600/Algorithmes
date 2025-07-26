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