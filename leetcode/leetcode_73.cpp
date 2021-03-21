/*
矩阵置零
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

class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool isRow0 = false;
        bool isCol0 = false;
        // 第一行是否有0
        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) {
                isRow0 = true;
                break;
            }
        }
        // 第一列是否有0
        for (int i = 1; i < row; ++i) {
            if (matrix[i][0] == 0) {
                isCol0 = true;
                break;
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < row; ++i) {
            if (matrix[i][0] == 0) {
                setRowZero(matrix, col, i);
            }
        }
        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) {
                setColZero(matrix, row, j);
            }
        }
        if (matrix[0][0] == 0) {
            setRowZero(matrix, col, 0);
            setColZero(matrix, row, 0);
        }
        if (isRow0) {
            setRowZero(matrix, col, 0);
        }
        if (isCol0) {
            setColZero(matrix, row, 0);
        }
    }
    void setRowZero(vector<vector<int>> &matrix, const int col, const int i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = 0;
        }
    }
    void setColZero(vector<vector<int>> &matrix, const int row, const int j) {
        for (int i = 0; i < row; ++i) {
            matrix[i][j] = 0;
        }
    }
};