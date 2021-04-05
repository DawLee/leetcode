
/*
旋转矩阵
easy
medium *
hard
*/

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }
        int row = matrix.size();
        for (int i = 0; i < row / 2; ++i) {
            retateLayer(matrix, row, i);
        }
    }
    void retateLayer(vector<vector<int>> &matrix, const int row,
                     const int layer) {
        int tmp = 0;
        for (int i = layer; i < row - layer - 1; ++i) {
            tmp = matrix[layer][i];
            matrix[layer][i] = matrix[row - i - 1][layer];
            matrix[row - i - 1][layer] = matrix[row - layer - 1][row - i - 1];
            matrix[row - layer - 1][row - i - 1] = matrix[i][row - layer - 1];
            matrix[i][row - layer - 1] = tmp;
        }
    }
};