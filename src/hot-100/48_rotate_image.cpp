#include <bits/stdc++.h>

class Solution {
    void swap_row(std::vector<std::vector<int>>& matrix, int j1, int j2) {
        for (int i = 0; i < matrix.size(); ++i) {
            std::swap(matrix[i][j1], matrix[i][j2]);
        }
    }

public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        int half = m >> 1;
        for (int j = 0; j < half; ++j) {
            swap_row(matrix, j, m - j - 1);
        }
    }
};

int main() {
}