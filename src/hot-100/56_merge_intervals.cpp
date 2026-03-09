#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> ans;
        if (intervals.empty()) return ans;
        std::sort(intervals.begin(), intervals.end());
        for (const auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            if (ans.empty() || ans.back()[1] < start) {
                ans.push_back({start, end});
            } else {
                ans.back()[1] = std::max(ans.back()[1], end);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}