/*
二维区域和检索 - 矩阵不可变
easy
medium *
hard
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class NumMatrix {
  public:
    vector<vector<int>> record;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            vector<int> tmp(col, 0);
            record.emplace_back(tmp);
            for (int j = 0; j < col; ++j) {
                if (i > 0 && j > 0) {
                    record[i][j] = matrix[i][j] + record[i - 1][j] +
                                   record[i][j - 1] - record[i - 1][j - 1];
                } else if (i > 0) {
                    record[i][j] = matrix[i][j] + record[i - 1][j];
                } else if (j > 0) {
                    record[i][j] = matrix[i][j] + record[i][j - 1];
                } else {
                    record[i][j] = matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum0 = 0;
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = record[row2][col2];
        if (row1 > 0 && col1 > 0) {
            sum0 = record[row1 - 1][col1 - 1];
        }
        if (row1 > 0) {
            sum1 = record[row1 - 1][col2];
        }
        if (col1 > 0) {
            sum2 = record[row2][col1 - 1];
        }
        return sum3 - sum2 - sum1 + sum0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */