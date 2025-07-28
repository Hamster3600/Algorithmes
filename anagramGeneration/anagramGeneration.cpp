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
        swapChars(str, k, i); // Backtrack
    }
}

int main() {
    std::string inputString = "abc";
    generateAnagrams(inputString, 0);
    return 0;
}