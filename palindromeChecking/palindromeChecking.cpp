/* 
Explanation of the algorithm:
1. The program checks whether a given string is a palindrome.
2. The function `isPalindrome`:
   - Compares characters from the beginning and end of the string, moving toward the center.
   - Returns `false` if any mismatch is found; otherwise, returns `true`.
3. The main function:
   - Defines a test string.
   - Calls `isPalindrome` and displays whether the string is a palindrome.
*/

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