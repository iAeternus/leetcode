// @see https://leetcode.cn/problems/gray-code
#include <bits/stdc++.h>

class Solution {
private:
    std::vector<int> res;

    void dfs(int path, int is_right, int depth, int n) {
        if (depth == n) {
            res.push_back(path);
            return;
        }

        dfs((path << 1) | is_right, 0, depth + 1, n);  // 左子树0，左0右1
        dfs((path << 1) | !is_right, 1, depth + 1, n); // 右子树1，左1右0
    }

public:
    std::vector<int> grayCode(int n) {
        dfs(0, 0, 0, n);
        return res;
    }
};

int main() {
    Solution s;
    int n = 2;

    auto res = s.grayCode(n);

    for (int it : res) {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    return 0;
}