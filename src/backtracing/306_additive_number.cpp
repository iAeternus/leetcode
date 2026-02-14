//! https://leetcode.cn/problems/additive-number
#include <bits/stdc++.h>

class Solution {
private:
    using i64 = long long;
    bool ok = false;
    std::vector<i64> a;

    bool checked_mul(i64 a, i64 b, i64& c) {
        if (a > LLONG_MAX / b) return false;
        c = a * b;
        return true;
    }

    bool checked_add(i64 a, i64 b, i64& c) {
        if (a > LLONG_MAX - b) return false;
        c = a + b;
        return true;
    }

    void dfs(const std::string& num, size_t pos) {
        if (ok) return;
        if (pos == num.length()) {
            if (a.size() >= 3) {
                ok = true;
            }
            return;
        }

        i64 curr = 0;
        for (auto i = pos; i < num.length(); ++i) {
            if (i > pos && num[pos] == '0') break;

            int d = num[i] - '0';
            if (!checked_mul(curr, 10, curr)) break;
            if (!checked_add(curr, d, curr)) break;

            if (a.size() >= 2) {
                i64 sum = a[a.size() - 1] + a[a.size() - 2];
                if (curr < sum) continue;
                if (curr > sum) break;
            }

            a.push_back(curr);
            dfs(num, i + 1);
            a.pop_back();
        }
    }

public:
    bool isAdditiveNumber(std::string num) {
        dfs(num, 0);
        return ok;
    }
};

int main() {
    Solution s;
    assert(s.isAdditiveNumber("112358"));
    assert(s.isAdditiveNumber("199100199"));
    std::cout << "All tests passed!\n";
}