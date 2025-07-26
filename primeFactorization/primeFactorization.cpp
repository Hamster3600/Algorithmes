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
