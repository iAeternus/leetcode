//! https://leetcode.cn/problems/path-sum-ii
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
    std::vector<std::vector<int>> res;
    std::vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) return;
        path.emplace_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            res.emplace_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }

public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};

int main() {
    return 0;
}