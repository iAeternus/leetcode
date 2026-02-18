//! https://leetcode.cn/problems/IlPe0q
#include <bits/stdc++.h>

class Solution {
public:
    /// 逆推
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i == 0) {
                    dp[i][j] = triangle[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }
        return *std::min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

    /// 顺推
    int minimumTotal2(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX)); // 需要默认值
        dp[0][0] = triangle[0][0];                                         // 需要初始化
        for (int i = 0; i + 1 < n; ++i) {                                  // 不需要遍历目标状态，因为目标状态不会发生转移
            for (int j = 0; j <= i; ++j) {
                dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
                dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
            }
        }
        return *std::min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

    /// 记忆化搜索
    int minimumTotal3(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX)); // 初始为非法值
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            auto& res = dp[i][j];
            if (res != INT_MAX) return res;
            if (i == 0) return res = triangle[i][j];
            if (j == 0) return res = dfs(i - 1, j) + triangle[i][j];
            if (i == j) return res = dfs(i - 1, j - 1) + triangle[i][j];
            return res = std::min(dfs(i - 1, j - 1), dfs(i - 1, j)) + triangle[i][j];
        };
        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            ans = std::min(ans, dfs(n - 1, j));
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3},
    };
    assert(s.minimumTotal(triangle) == 11);
    assert(s.minimumTotal2(triangle) == 11);
    assert(s.minimumTotal3(triangle) == 11);
    std::cout << "All tests passed!\n";
    return 0;
}