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
    int countArrangement(int n) {
        vis.resize(n + 1, false);
        dfs(n, 1);
        return res;
    }
};

int main() {
    Solution s;
    int n = 2;
    std::cout << s.countArrangement(n) << '\n';
    return 0;
}