#include <bits/stdc++.h>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end() - k);
        std::reverse(nums.end() - k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

bool vec_eq(const std::vector<int>& v1, const std::vector<int>& v2) {
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    Solution s;

    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> ans = {5, 6, 7, 1, 2, 3, 4};
    s.rotate(nums, 3);
    assert(vec_eq(nums, ans));

    nums = {-1, -100, 3, 99};
    ans = {3, 99, -1, -100};
    s.rotate(nums, 2);
    assert(vec_eq(nums, ans));

    std::cout << "All Test Passed!\n";
    return 0;
}