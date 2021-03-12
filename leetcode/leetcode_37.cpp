/*
解数独
easy
medium
hard   *
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
    void solveSudoku(vector<vector<char>> &board) { backtracking(board); }
    bool backtracking(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char k = '1'; k <= '9'; ++k) {
                    if (isValid(board, i, j, k)) {
                        board[i][j] = k;
                        if (backtracking(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool isValid(const vector<vector<char>> &board, int row, int col,
                 char num) {
        for (int i = 0; i < board.size(); ++i) {
            if (i == row) {
                continue;
            }
            if (board[i][col] == num) {
                return false;
            }
        }
        for (int j = 0; j < board[0].size(); ++j) {
            if (j == col) {
                continue;
            }
            if (board[row][j] == num) {
                return false;
            }
        }
        int r = 3 * (row / 3);
        int c = 3 * (col / 3);
        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                if (i == row || j == col) {
                    continue;
                }
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
};