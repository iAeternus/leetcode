// @see https://leetcode.cn/problems/unique-binary-search-trees-ii
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

void clear(TreeNode*& t) {
    if (t == nullptr) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = nullptr;
}

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
    int n;
    std::cin >> n;

    Solution s;
    auto res = s.generateTrees(n);

    std::cout << res.size() << '\n';

    for (auto& it : res) {
        clear(it);
    }
}