//! https://leetcode.cn/problems/path-with-maximum-gold
//! 不知为何会编译错误，可能是编译器行为不一致
#include <bits/stdc++.h>

class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool is_valid(int n, int m, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_sum = 0;

        int total_sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                total_sum += grid[i][j];
            }
        }

        auto dfs = [&](this auto&& dfs, int x, int y, int sum) -> void {
            sum += grid[x][y];
            max_sum = std::max(max_sum, sum);
            if (max_sum == total_sum) {
                return; // 以达到最大，剪枝
            }

            int gold = grid[x][y];
            grid[x][y] = 0;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (is_valid(n, m, nx, ny) && grid[nx][ny] > 0) {
                    dfs(nx, ny, sum);
                }
            }
            grid[x][y] = gold;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) {
                    dfs(i, j, 0);
                }
            }
        }
        return max_sum;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0},
    };

    std::cout << s.getMaximumGold(grid) << '\n';

    return 0;
}