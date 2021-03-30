/*
顺时针打印矩阵
easy   *
medium
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
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int len = row * col;
        res.resize(row * col, 0);
        int index = 0;
        vector<vector<int>> dire = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        pair<int, int> cur = {0, 0};
        int d = 0;
        while (index < len) {
            res[index] = matrix[cur.first][cur.second];
            visit[cur.first][cur.second] = true;
            pair<int, int> next = {cur.first + dire[d][0],
                                   cur.second + dire[d][1]};
            if (!isLegal(visit, next, row, col)) {
                d = (d + 1) % dire.size();
                next.first = cur.first + dire[d][0];
                next.second = cur.second + dire[d][1];
            }
            cur = next;
            ++index;
        }
        return res;
    }
    bool isLegal(const vector<vector<bool>> &visit, const pair<int, int> &cur,
                 const int row, const int col) {
        int x = cur.first;
        int y = cur.second;
        if (x < 0 || x >= row || y < 0 || y >= col || visit[x][y]) {
            return false;
        }
        return true;
    }
};