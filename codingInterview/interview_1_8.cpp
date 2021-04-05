// coding Interview 1_8
// 零矩阵
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        // 第 0 行是否有0
        bool isZeroRow = false;
        bool isZeroCol = false;
        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) {
                isZeroRow = true;
                break;
            }
        }
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < row; ++i) {
            if (matrix[i][0] == 0) {
                setRowAllZero(matrix, col, i);
            }
        }
        for (int j = 1; j < col; ++j) {
            if (matrix[0][j] == 0) {
                setColAllZero(matrix, row, j);
            }
        }
        if (isZeroRow) {
            setRowAllZero(matrix, col, 0);
        }
        if (isZeroCol) {
            setColAllZero(matrix, row, 0);
        }
    }
    void setRowAllZero(vector<vector<int>> &matrix, const int col, int index) {
        for (int j = 0; j < col; ++j) {
            matrix[index][j] = 0;
        }
    }
    void setColAllZero(vector<vector<int>> &matrix, const int row, int index) {
        for (int i = 0; i < row; ++i) {
            matrix[i][index] = 0;
        }
    }
};