#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    auto time = std::to_string(h) + ":" + (m < 10 ? "0" : "") + std::to_string(m);
                    res.push_back(time);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int turnedOn = 1;
    auto res = s.readBinaryWatch(turnedOn);
    for (const auto& time : res) {
        std::cout << time << '\n';
    }
    return 0;
}