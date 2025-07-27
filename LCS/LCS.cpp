#include <iostream>
#include <string>
#include <vector>

int custom_max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubsequenceLength(const std::string& text1, const std::string& text2) {
    int m = text1.length();
    int n = text2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = custom_max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string s1 = "AGGTAB";
    std::string s2 = "GXTXAYB";
    std::cout << "Length of LCS for \"" << s1 << "\" and \"" << s2 << "\" is "
              << longestCommonSubsequenceLength(s1, s2) << std::endl;

    return 0;
}