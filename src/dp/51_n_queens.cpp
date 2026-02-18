//! https://leetcode.cn/problems/n-queens
#include <bits/stdc++.h>

class Solution {
private:
    std::vector<std::vector<std::string>> res;

    // a[r] = c 表示：第 r 行的皇后放在第 c 列
    // 仅用于最后构造棋盘
    int a[10] = {0};

    void add_res(int n) {
        std::vector<std::string> buf(n, std::string(n, '.'));
        for (int i = 0; i < n; ++i) {
            buf[i][a[i]] = 'Q';
        }
        res.push_back(buf);
    }

    /**
     * 状压 DFS
     * @param row 当前处理到第 row 行
     * @param cols 已占用的列集合（bitmask，第 c 位为 1 表示列 c 被占）
     * @param diag1 已占用的主对角线集合（/ 方向）
     * @param diag2 已占用的副对角线集合（\ 方向）
     */
    void dfs(int n, int row, int cols, int diag1, int diag2) {
        if (row == n) {
            add_res(n);
            return;
        }

        /*
         * 计算当前行可以放皇后的位置集合：
         * 1. cols | diag1 | diag2 表示“被攻击的位置集合”
         * 2. 取反得到“可放的位置集合”
         * 3. 再与 (1<<n)-1 取交集，保证只考虑前 n 列
         *
         * available 是一个集合（bitmask）：
         * 第 i 位为 1，表示第 i 列可以放皇后
         */
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        /*
         * 枚举 available 集合中的每一个元素（每一个可选列）
         * 这是对“集合状态”进行递推
         */
        while (available) {
            // 取出集合中的一个元素（最低位的 1）
            int p = available & -available;
            available -= p;

            // 记录该行皇后放在第几列（用于最终构造棋盘）
            int col = __builtin_ctz(p); // p 是 2^col
            a[row] = col;

            /*
             * 状态转移：
             * 把 p 加入三个集合中，并进入下一行
             *
             * cols  | p        : 占用当前列
             * (diag1 | p) << 1 : 下一行时，主对角线整体左移
             * (diag2 | p) >> 1 : 下一行时，副对角线整体右移
             */
            dfs(n,
                row + 1,
                cols | p,
                (diag1 | p) << 1,
                (diag2 | p) >> 1);
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        // 初始状态三个集合都为空
        dfs(n, 0, 0, 0, 0);
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