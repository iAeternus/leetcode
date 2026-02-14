//! https://leetcode.cn/problems/unique-binary-search-trees-ii
#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :
            val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :
            val(x), left(left),
            right(right) {}
};

class Solution {
private:
    void dfs(int l, int r, std::vector<TreeNode*>& res) {
        if (l > r) {
            res.push_back(nullptr);
            return;
        }
        if (l == r) {
            res.push_back(new TreeNode(l));
            return;
        }

        std::vector<TreeNode*> l_subtrees, r_subtrees;
        for (int i = l; i <= r; ++i) {
            l_subtrees.clear();
            r_subtrees.clear();
            dfs(l, i - 1, l_subtrees);
            dfs(i + 1, r, r_subtrees);
            for (const auto& l_subtree : l_subtrees) {
                for (const auto& r_subtree : r_subtrees) {
                    res.push_back(new TreeNode(i, l_subtree, r_subtree));
                }
            }
        }
    }

public:
    std::vector<TreeNode*> generateTrees(int n) {
        std::vector<TreeNode*> res;
        dfs(1, n, res);
        return res;
    }
};

int main() {
    return 0;
}