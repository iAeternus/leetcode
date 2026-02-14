//! https://leetcode.cn/problems/matchsticks-to-square
#include <bits/stdc++.h>

class Solution {
private:
    int edges[4] = {0};

    bool dfs(const std::vector<int>& matchsticks, int idx, int len) {
        if (idx == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            if (edges[i] == len
                || edges[i] + matchsticks[idx] > len
                || (i > 0 && edges[i] == edges[i - 1])) { // 去除对称
                continue;
            }
            edges[i] += matchsticks[idx];
            if (dfs(matchsticks, idx + 1, len)) {
                return true;
            }
            edges[i] -= matchsticks[idx];
        }
        return false;
    }

public:
    bool makesquare(std::vector<int>& matchsticks) {
        int total_len = 0;
        for (int len : matchsticks) {
            total_len += len;
        }
        if (total_len % 4 != 0) {
            return false;
        }

        std::sort(matchsticks.begin(), matchsticks.end(), [](const int a, const int b) {
            return a > b;
        });
        return dfs(matchsticks, 0, total_len / 4);
    }
};

int main() {
    Solution s;
    std::vector<int> matchsticks = {1, 1, 2, 2, 2};
    std::cout << s.makesquare(matchsticks) << '\n';
    return 0;
}