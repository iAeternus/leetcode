// https://leetcode.cn/problems/invert-binary-tree
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
    void invert_tree(TreeNode* root) {
        if (!root) return;
        invert_tree(root->left);
        invert_tree(root->right);
        std::swap(root->left, root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        invert_tree(root);
        return root;
    }
};

int main() {
}