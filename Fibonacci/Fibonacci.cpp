/* 
Explanation of the algorithm:
1. The program generates the Fibonacci sequence up to a specified number of terms.
2. The main function:
   - Prompts the user to input the number of terms to generate.
   - Validates the input to ensure it is within the allowed range.
   - Initializes the first two terms of the Fibonacci sequence.
   - Iteratively calculates subsequent terms using the formula: `F(n) = F(n-1) + F(n-2)`.
   - Displays the generated sequence.
*/

#include <iostream>

int main() {
    const int MAX_SIZE = 1000;
    int fibonacci[MAX_SIZE];
    int n;

    std::cout << "Enter how many Fibonacci numbers to generate: ";
    std::cin >> n;

    if (n <= 0 || n > MAX_SIZE) {
        std::cout << "Invalid number!" << std::endl;
        return 1;
    }

    fibonacci[0] = 0;
    if (n > 1) {
        fibonacci[1] = 1;
    }

    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    std::cout << "\nFibonacci sequence:\n";
    for (int i = 0; i < n; i++) {
        std::cout << fibonacci[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
