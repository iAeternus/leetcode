// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree
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
    TreeNode* helper(std::vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main() {
}