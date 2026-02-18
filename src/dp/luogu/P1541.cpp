//! https://www.luogu.com.cn/problem/P1541
#include <bits/stdc++.h>

const int MAX_CARDS = 45;
const int MAX_N = 355;
int n, m;
int w[MAX_N], dp[MAX_CARDS][MAX_CARDS][MAX_CARDS][MAX_CARDS];
int c[5];

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> w[i];
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        std::cin >> x;
        c[x]++;
    }

    dp[0][0][0][0] = w[1];
    for (int i = 0; i <= c[1]; ++i) {
        for (int j = 0; j <= c[2]; ++j) {
            for (int k = 0; k <= c[3]; ++k) {
                for (int l = 0; l <= c[4]; ++l) {
                    int x = i + 2 * j + 3 * k + 4 * l + 1;
                    if (i) dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i - 1][j][k][l] + w[x]);
                    if (j) dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j - 1][k][l] + w[x]);
                    if (k) dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j][k - 1][l] + w[x]);
                    if (l) dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j][k][l - 1] + w[x]);
                }
            }
        }
    }

    std::cout << dp[c[1]][c[2]][c[3]][c[4]] << '\n';

    return 0;
}