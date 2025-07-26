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