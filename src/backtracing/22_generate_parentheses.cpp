//! https://leetcode.cn/problems/generate-parentheses
#include <bits/stdc++.h>

class Solution {
private:
    std::string path;
    std::vector<std::string> res;

    void dfs(int lcnt, int rcnt, int n) {
        if (path.length() == n * 2) {
            res.push_back(path);
            return;
        }

        if (lcnt < n) {
            path += '(';
            dfs(lcnt + 1, rcnt, n);
            path.pop_back();
        }
        if (rcnt < lcnt) {
            path += ')';
            dfs(lcnt, rcnt + 1, n);
            path.pop_back();
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        dfs(0, 0, n);
        return res;
    }
};

int main() {
    int n;
    std::cin >> n;
    Solution s;
    auto res = s.generateParenthesis(n);
    for(const auto& path : res) {
        std::cout << path << '\n';
    }
    return 0;
}