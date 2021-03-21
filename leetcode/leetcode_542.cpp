/*
01 矩阵
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
    vector<vector<int>> dire{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> visit(row, vector<int>(col, 0));
        queue<pair<int, int>> record;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    record.emplace(i, j);
                    visit[i][j] = 1;
                }
            }
        }
        while (!record.empty()) {
            auto [i, j] = record.front();
            record.pop();
            for (int d = 0; d < 4; ++j) {
                int x = i + dire[d][0];
                int y = j + dire[d][1];
                if (x >= 0 && x < row && y >= 0 && y < col &&
                    visit[x][y] == 0) {
                    matrix[x][y] = matrix[i][j] + 1;
                    record.emplace(x, y);
                    visit[x][y] = 1;
                }
            }
        }
        return matrix;
    }
};
