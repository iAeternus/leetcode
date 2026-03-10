#include <bits/stdc++.h>

class Solution {
private:
    // 右下左上
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool is_valid(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        std::vector<int> ans(n * m);
        int i = 0, j = 0, dir = 0;
        for (int k = 0; k < n * m; ++k) {
            ans[k] = matrix[i][j];
            matrix[i][j] = INT_MAX;
            int x = i + dx[dir];
            int y = j + dy[dir];
            if (!is_valid(x, y, n, m) || matrix[x][y] == INT_MAX) {
                dir = (dir + 1) % 4;
            }
            i += dx[dir];
            j += dy[dir];
        }
        return ans;
    }
};

int main() {
}