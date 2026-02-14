//! https://leetcode.cn/problems/combinations
#include <bits/stdc++.h>

class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;

    void dfs(int curr, int n, int k) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = curr; i <= n; ++i) {
            path.push_back(i);
            dfs(i + 1, n, k);
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
};

int main() {
    Solution s;
    int n = 4, k = 2;

    auto res = s.combine(n, k);

    for (const auto& path : res) {
        for (int it : path) {
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}