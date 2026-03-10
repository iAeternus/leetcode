// https://leetcode.cn/problems/symmetric-tree
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
    bool is_symmetric(TreeNode* x, TreeNode* y) {
        if (!x && !y) return true;
        if (!x || !y) return false;
        if (x->val != y->val) return false;
        return is_symmetric(x->left, y->right) && is_symmetric(x->right, y->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return is_symmetric(root->left, root->right);
    }
};

int main() {
}