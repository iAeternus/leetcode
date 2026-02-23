//! https://www.luogu.com.cn/problem/U596568
#include <bits/stdc++.h>

const int N = 1e2 + 5;
int t, n;
int a[N];

bool check(int sp) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (a[i] + sp - 1) / sp;
    }
    return sum <= t;
}

int main() {
    std::cin >> t >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int l = 1;
    int r = *std::max_element(a, a + n);
    int ans = l;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    std::cout << ans << '\n';
    return 0;
}