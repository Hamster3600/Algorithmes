/* 
Explanation of the algorithm:
1. The program implements the naive pattern searching algorithm to find all occurrences of a pattern in a text.
2. The function `naivePatternSearch`:
   - Iterates through the text, checking each substring of the same length as the pattern.
   - Compares the substring with the pattern character by character.
   - Stores the starting index of matches in a vector.
3. The main function:
   - Defines a text and a pattern.
   - Calls `naivePatternSearch` to find and display all occurrences of the pattern in the text.
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<int> naivePatternSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> foundIndices;
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            foundIndices.push_back(i);
        }
    }

    return foundIndices;
}

int main() {
    std::string myText = "ABABCABABABABC";
    std::string myPattern = "ABABC";

    std::vector<int> results = naivePatternSearch(myText, myPattern);

    if (results.empty()) {
        std::cout << "Pattern '" << myPattern << "' not found in the text." << std::endl;
    } else {
        std::cout << "Pattern '" << myPattern << "' found at indices: ";
        for (int index : results) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}