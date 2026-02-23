//! https://leetcode.cn/problems/longest-palindromic-substring
#include <bits/stdc++.h>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.length();
        if (n < 2) {
            return s;
        }

        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        int begin = 0;
        int max_len = 1;
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i < n; ++i) {
                int j = l + i - 1;
                if (j >= n) break;

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, max_len);
    }
};

int main() {
    Solution s;
    assert(s.longestPalindrome("babad") == "bab");
    assert(s.longestPalindrome("cbbd") == "bb");
    std::cout << "All tests passed!\n";
    return 0;
}