// @see https://leetcode.cn/problems/word-search
#include <bits/stdc++.h>

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    std::vector<std::vector<bool>> vis;

    bool is_valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool dfs(int x, int y, int idx, const std::vector<std::vector<char>>& board,
             const std::string& word) {
        if (idx >= word.length()) {
            return true;
        }
        if (!is_valid(x, y, board.size(), board[0].size())) {
            return false;
        }
        if (vis[x][y]) {
            return false;
        }
        if (board[x][y] != word[idx]) {
            return false;
        }

        for (int i = 0; i < 4; ++i) {
            vis[x][y] = true;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (dfs(nx, ny, idx + 1, board, word)) {
                return true;
            }
            vis[x][y] = false;
        }
        return false;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        if (m * n < word.length()) {
            return false;
        }
        vis.resize(m, std::vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    std::string word = "ABCCED";

    std::cout << s.exist(board, word) << '\n';

    return 0;
}