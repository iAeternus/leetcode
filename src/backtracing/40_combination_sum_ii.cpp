//! https://leetcode.cn/problems/combination-sum-ii
#include <bits/stdc++.h>

class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;
    std::vector<bool> vis;

    void dfs(int idx, int sum, const std::vector<int>& candidates, int target) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            if (vis[i]) continue;
            if (i && candidates[i] == candidates[i - 1] && !vis[i - 1]) continue;
            vis[i] = true;
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(i, sum, candidates, target);
            vis[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        vis.resize(candidates.size(), false);
        std::sort(candidates.begin(), candidates.end());
        dfs(0, 0, candidates, target);
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    auto res = s.combinationSum2(candidates, target);

    for (const auto& path : res) {
        for (int it : path) {
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}