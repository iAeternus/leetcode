//! https://leetcode.cn/problems/unique-binary-search-trees
//! https://leetcode.cn/problems/unique-binary-search-trees-ii
#include <bits/stdc++.h>

class Solution {
public:
    // G(n): 有n个节点的BST个数为G(n)
    // f(j): 以j为根节点的BST个数为f(j)
    // 当j为根时，其左子树有j-1个节点，右子树有n-j个节点
    // 故f(j) = G(j - 1) * G(n - j)
    // G(n) = \sum_{j = 1}^n f(j) = \sum_{j = 1}^n G(j - 1) * G(n - j)
    // G(0) = G(1) = 1
    int numTrees(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main() {
    int n;
    std::cin >> n;
    Solution s;
    std::cout << s.numTrees(n) << '\n';
    return 0;
}