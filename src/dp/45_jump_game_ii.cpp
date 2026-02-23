//! https://leetcode.cn/problems/jump-game-ii
#include <bits/stdc++.h>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        std::vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= nums[i] && i + j < n; ++j) {
                dp[i + j] = std::min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {2, 3, 1, 1, 4};
    assert(s.jump(nums) == 2);

    nums = {2, 3, 0, 1, 4};
    assert(s.jump(nums) == 2);

    std::cout << "All tests passed!\n";
    return 0;
}