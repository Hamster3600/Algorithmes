/* 
Explanation of the algorithm:
1. The program generates all possible anagrams of a given string.
2. The function `swapChars`:
   - Swaps two characters in the string to create permutations.
3. The function `generateAnagrams`:
   - Recursively generates anagrams by swapping characters at different positions.
   - Stops when all characters have been fixed in their positions.
   - Prints each generated anagram.
4. The main function:
   - Defines a test string.
   - Calls `generateAnagrams` to compute and display all anagrams.
*/

#include <iostream>
#include <string>
#include <vector>

void swapChars(std::string& str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void generateAnagrams(std::string str, int k) {
    if (k == str.length()) {
        std::cout << str << std::endl;
        return;
    }

    for (int i = k; i < str.length(); i++) {
        swapChars(str, k, i);
        generateAnagrams(str, k + 1);
        swapChars(str, k, i);
    }
}

int main() {
    std::string inputString = "abc";
    generateAnagrams(inputString, 0);
    return 0;
}