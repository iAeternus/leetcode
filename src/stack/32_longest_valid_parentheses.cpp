#include <bits/stdc++.h>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int max_ans = 0, n = s.length();
        std::vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    // i-2 i-1 i
                    // ... (   )
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    //         i-2 i-1 i
                    // ... ( ( ... )   )
                    //       ^^^^^^^ dp[i - 1]
                    //     ^           ^ new in
                    // ^^^ dp[i - dp[i - 1] - 2]
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                max_ans = std::max(max_ans, dp[i]);
            }
        }
        return max_ans;
    }

    int longestValidParentheses2(std::string s) {
        std::stack<int> st;
        st.push(-1); // 虚拟红线（哨兵）
        int ans = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {                     // 炸弹
                st.push(i);                        // 记录炸弹下标
            } else if (st.size() > 1) {            // 栈顶是炸弹
                st.pop();                          // 拆弹
                ans = std::max(ans, i - st.top()); // 右端点为 i 时，左端点最小是 stk.top() + 1
            } else {                               // 栈只有一个数，是红线，s[i] 无法拆弹，成为新的红线
                st.top() = i;                      // 后续合法子串不能包含s[i]，替换栈底
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    assert(s.longestValidParentheses("(()") == 2);
    assert(s.longestValidParentheses(")()())") == 4);
    assert(s.longestValidParentheses("") == 0);

    assert(s.longestValidParentheses2("(()") == 2);
    assert(s.longestValidParentheses2(")()())") == 4);
    assert(s.longestValidParentheses2("") == 0);

    std::cout << "All tests passed!\n";
    return 0;
}