//! https://leetcode.cn/problems/beautiful-arrangement/description
#include <bits/stdc++.h>

class Solution {
private:
    int res = 0;
    std::vector<bool> vis;

    void dfs(int n, int idx) {
        if (idx == n + 1) {
            res++;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            if (idx % i == 0 || i % idx == 0) {
                vis[i] = true;
                dfs(n, idx + 1);
                vis[i] = false;
            }
        }
    }

public:
    /// dfs
    int countArrangement(int n) {
        vis.resize(n + 1, false);
        dfs(n, 1);
        return res;
    }

    /// 记忆化搜索
    int countArrangement2(int n) {
        std::vector<int> memo(1 << n, -1);
        auto dfs = [&](this auto&& dfs, int s) -> int {
            if (s == (1 << n) - 1) {
                return 1;
            }
            int& res = memo[s];
            if (res != -1) {
                return res;
            }
            res = 0;
            int i = std::popcount((unsigned)s) + 1; // idx
            for (int j = 1; j <= n; ++j) {
                if (((s >> (j - 1)) & 1) == 0 && (i % j == 0 || j % i == 0)) {
                    res += dfs(s | (1 << (j - 1)));
                }
            }
            return res;
        };
        return dfs(0);
    }

    /// 状压dp：用位集合表示状态空间，对集合进行动态规划
    ///
    /// 状压 DP的一般结构
    /// dp[mask] = 在“当前集合 mask”的情况下的最优解 / 方案数 / 可行性
    int countArrangement3(int n) {
        int N = 1 << n;
        std::vector<int> dp(N, 0);
        dp[0] = 1;

        for (int s = 0; s < N; ++s) {
            int i = std::popcount((unsigned)s) + 1; // idx
            for (int j = 1; j <= n; ++j) {
                if ((s >> (j - 1)) & 1) continue;
                if (i % j == 0 || j % i == 0) {
                    int ns = s | (1 << (j - 1));
                    dp[ns] += dp[s];
                }
            }
        }

        return dp[N - 1];
    }
};

int main() {
    Solution s;
    int n = 2;
    std::cout << s.countArrangement(n) << '\n';
    std::cout << s.countArrangement2(n) << '\n';
    std::cout << s.countArrangement3(n) << '\n';
    return 0;
}