#include <bits/stdc++.h>

class Solution {
private:
    int res = 0;
    std::string path;
    bool vis[10] = {false};

    void dfs(int n) {
        if (path.size() == n) {
            res++;
            return;
        }
        if (path.length() >= 1 && path[0] == '0') {
            return;
        }

        for (int i = 0; i <= 9; ++i) {
            if (vis[i]) continue;
            path += i + '0';
            vis[i] = true;
            dfs(n);
            path.pop_back();
            vis[i] = false;
        }
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        for (int i = 1; i <= n; ++i) {
            path.clear();
            memset(vis, 0, sizeof(vis));
            dfs(i);
        }
        return res;
    }

    int countNumbersWithUniqueDigits2(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int res = 10, curr = 9;
        for (int i = 0; i < n - 1; ++i) {
            curr *= 9 - i;
            res += curr;
        }
        return res;
    }
};

int main() {
    Solution s;
    int n = 2;
    std::cout << s.countNumbersWithUniqueDigits(n) << '\n';
    std::cout << s.countNumbersWithUniqueDigits2(n) << '\n';
    return 0;
}