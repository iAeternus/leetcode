/// https://leetcode.cn/problems/combination-sum
/// https://leetcode.cn/problems/combination-sum-ii
#include <bits/stdc++.h>

class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> res;

    void dfs(int idx, int sum, const std::vector<int>& candidates, int target) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(i, sum, candidates, target);
            path.pop_back();
            sum -= candidates[i];
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        dfs(0, 0, candidates, target);
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    auto res = s.combinationSum(candidates, target);

    for (const auto& path : res) {
        for (int it : path) {
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}