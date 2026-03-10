// https://leetcode.cn/problems/diameter-of-binary-tree
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
    int max_ans;

    int height(TreeNode* root) {
        if (!root) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        max_ans = std::max(max_ans, left_height + right_height);
        return std::max(left_height, right_height) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_ans = 0;
        height(root);
        return max_ans;
    }
};

int main() {
}