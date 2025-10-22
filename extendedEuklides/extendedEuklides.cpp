/*
Explanation of the algorithm:
1. The program implements the Extended Euclidean Algorithm to find the Greatest Common Divisor (GCD) and the coefficients for Bézout's identity.
2. The function `extended_gcd`:
   - Recursively computes the GCD and the coefficients x and y such that a*x + b*y = gcd(a, b).
   - Base case: when b == 0, gcd = a, x = 1, y = 0.
   - Recursive case: calls itself with b and a % b, then updates x = y1, y = x1 - (a / b) * y1.
3. The main function:
   - Prompts the user to input numbers a, b, and c.
   - Computes the GCD and coefficients x0, y0 for a and b.
   - Checks if c is divisible by the GCD.
   - If yes, scales the coefficients by c / gcd to find x and y such that a*x + b*y = c.
   - If not, indicates that no solution exists.
*/
#include <iostream>

void extended_gcd(int a, int b, int &gcd_val, int &x, int &y) {
    if (b == 0) {
        gcd_val = a;
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    extended_gcd(b, a % b, gcd_val, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

int main() {
    int a, b, c;
    std::cout << "Give the number a: ";
    std::cin >> a;
    std::cout << "Give the number b: ";
    std::cin >> b;
    std::cout << "Give the number c: ";
    std::cin >> c;

    int g, x0, y0;
    extended_gcd(a, b, g, x0, y0);

    if (c % g != 0) {
        std::cout << "GDC can't be equal to " << c;
    } else {
        int k = c / g;
        int x = x0 * k;
        int y = y0 * k;
        std::cout << "Can be equal to " << c << std::endl;
        std::cout << "x = " << x << " y = " << y << std::endl;
    }

    return 0;
}