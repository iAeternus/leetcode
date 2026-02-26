//! https://leetcode.cn/problems/valid-parentheses
#include <bits/stdc++.h>

class Solution {
private:
    bool is_match(char a, char b) {
        return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
    }
public:
    bool isValid(std::string s) {
        int n = s.length();
        std::stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty() || !is_match(st.top(), c)) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;

    assert(s.isValid("()") == true);
    assert(s.isValid("()[]{}") == true);
    assert(s.isValid("(]") == false);
    assert(s.isValid("([])") == true);
    assert(s.isValid("([)]") == false);

    std::cout << "All tests passed!\n";
    return 0;
}