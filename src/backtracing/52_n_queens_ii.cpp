#include <bits/stdc++.h>

class Solution {
private:
    int cnt = 0;
    int a[10] = {0};

    bool check(int r) {
        for (int i = 0; i < r; ++i) {
            if (a[i] == a[r] || abs(a[i] - a[r]) == abs(i - r)) {
                return false;
            }
        }
        return true;
    }

    void dfs(int n, int r) {
        if (r >= n) {
            ++cnt;
            return;
        }

        for (int i = 0; i < n; ++i) {
            a[r] = i;
            if (check(r)) {
                dfs(n, r + 1);
            }
        }
    }

public:
    int totalNQueens(int n) {
        dfs(n, 0);
        return cnt;
    }
};

int main() {
    int n = 4;
    Solution s;
    std::cout << s.totalNQueens(n) << '\n';
    return 0;
}