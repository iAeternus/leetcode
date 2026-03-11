// https://leetcode.cn/problems/number-of-islands
#include <bits/stdc++.h>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int n = grid.size(), m = grid[0].size();

        auto is_valid = [&](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        auto dfs = [&](this auto&& dfs, int x, int y) -> void {
            if (!is_valid(x, y) || grid[x][y] == '0') return;
            grid[x][y] = '0';
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                dfs(nx, ny);
            }
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    std::vector<std::vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    assert(s.numIslands(grid) == 1);

    grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    assert(s.numIslands(grid) == 3);

    std::cout << "All Tests Passed!\n";
}