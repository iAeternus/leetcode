//! https://leetcode.cn/problems/n-queens
#include <bits/stdc++.h>

class Solution {
private:
    std::vector<std::vector<std::string>> res;
    int a[10] = {0}; // a[i] = j，第i行皇后在第j列

    void add_res(int n) {
        std::vector<std::string> buf(n, std::string(n, '.'));
        for (int i = 0; i < n; ++i) {
            buf[i][a[i]] = 'Q';
        }
        res.push_back(buf);
    }

    bool check(int r) {
        for (int i = 0; i < r; ++i) {
            if (a[i] == a[r] || abs(a[i] - a[r]) == abs(i - r)) {
                return false;
            }
        }
        return true;
    }

    void dfs(int n, int r) {
        if (r >= n) {
            add_res(n);
            return;
        }

        for (int i = 0; i < n; ++i) {
            a[r] = i;
            if (check(r)) {
                dfs(n, r + 1);
            }
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        dfs(n, 0);
        return res;
    }
};

int main() {
    int n = 8;
    Solution s;

    auto res = s.solveNQueens(n);

    for (const auto& path : res) {
        for (const auto& row : path) {
            std::cout << row << '\n';
        }
        std::cout << '\n';
    }
}