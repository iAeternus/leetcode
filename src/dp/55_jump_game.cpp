//! https://leetcode.cn/problems/jump-game
#include <bits/stdc++.h>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        std::vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= nums[i] && i + j < n; ++j) {
                dp[i + j] = dp[i];
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {2, 3, 1, 1, 4};
    assert(s.canJump(nums) == true);

    nums = {3, 2, 1, 0, 4};
    assert(s.canJump(nums) == false);

    std::cout << "All tests passed!\n";
    return 0;
}