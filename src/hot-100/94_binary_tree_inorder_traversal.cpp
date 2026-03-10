// https://leetcode.cn/problems/binary-tree-inorder-traversal
#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :
            val(x), left(left), right(right) {}
};

class Solution {
private:
    void inorder_traversal(TreeNode* root, std::vector<int>& ans) {
        if (!root) return;
        inorder_traversal(root->left, ans);
        ans.push_back(root->val);
        inorder_traversal(root->right, ans);
    }

public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        inorder_traversal(root, ans);
        return ans;
    }
};

int main() {
}