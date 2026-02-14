//! https://leetcode.cn/problems/permutations-ii
#include <bits/stdc++.h>

class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    std::vector<bool> vis;

    void dfs(const std::vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i]) continue;
            if (i && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
            vis[i] = true;
            path.push_back(nums[i]);
            dfs(nums);
            vis[i] = false;
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        vis.resize(nums.size());
        std::sort(nums.begin(), nums.end());
        dfs(nums);
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1, 1, 2};

    auto res = s.permuteUnique(nums);

    for (const auto& path : res) {
        for (int it : path) {
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}