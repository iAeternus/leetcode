// https://leetcode.cn/problems/binary-tree-level-order-traversal
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
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if (!root) return ans;

        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ans.push_back({});
            int curr_level_size = q.size();
            for (int i = 0; i < curr_level_size; ++i) {
                auto* node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return ans;
    }
};

int main() {
}