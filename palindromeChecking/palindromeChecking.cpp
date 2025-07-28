#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::string test = "racecar";

    std::cout << "'" << test << "' is palindrome: " << (isPalindrome(test) ? "true" : "false") << std::endl;
    return 0;
}