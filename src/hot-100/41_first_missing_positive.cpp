#include <bits/stdc++.h>

class Solution {
public:
    // 题目要求常量空间，不能开哈希表
    // 考虑原地哈希
    int firstMissingPositive(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i] - 1] == nums[i]) {
                    break;
                }
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main() {
    Solution s;

    std::vector<int> nums = {1, 2, 0};
    assert(s.firstMissingPositive(nums) == 3);

    nums = {3, 4, -1, 1};
    assert(s.firstMissingPositive(nums) == 2);

    nums = {7, 8, 9, 11, 12};
    assert(s.firstMissingPositive(nums) == 1);

    std::cout << "All Test Passed!\n";
}