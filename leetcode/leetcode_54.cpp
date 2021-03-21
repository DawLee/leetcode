/*
螺旋矩阵
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
    vector<vector<int>> dire{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> cur = {0, 0};
        res.emplace_back(matrix[cur[0]][cur[1]]);
        matrix[cur[0]][cur[1]] += 300;
        while (true) {
            int d = getDire(matrix, cur);
            if (d == -1) {
                break;
            }
            cur[0] += dire[d][0];
            cur[1] += dire[d][1];
            while (isLegal(matrix, cur)) {
                res.emplace_back(matrix[cur[0]][cur[1]]);
                matrix[cur[0]][cur[1]] += 300;
                cur[0] += dire[d][0];
                cur[1] += dire[d][1];
            }
            cur[0] -= dire[d][0];
            cur[1] -= dire[d][1];
        }
        return res;
    }
    int getDire(const vector<vector<int>> &matrix, const vector<int> cur) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < dire.size(); ++i) {
            vector<int> next = {cur[0] + dire[i][0], cur[1] + dire[i][1]};
            if (isLegal(matrix, next)) {
                return i;
            }
        }
        return -1;
    }
    bool isLegal(const vector<vector<int>> &matrix, const vector<int> cur) {
        if (cur[0] >= 0 && cur[0] < matrix.size() && cur[1] >= 0 &&
            cur[1] < matrix[0].size() && matrix[cur[0]][cur[1]] < 101) {
            return true;
        }
        return false;
    }
};