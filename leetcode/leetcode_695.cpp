/*
岛屿的最大面积
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
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int res = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visit(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    int tmp = bfs(grid, visit, i, j);
                    res = max(tmp, res);
                }
            }
        }
        return res;
    }
    int bfs(vector<vector<int>> &grid, vector<vector<int>> &visit, int i,
            int j) {
        vector<vector<int>> dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int row = grid.size();
        int col = grid[0].size();
        int area = 1;
        queue<vector<int>> record;
        vector<int> cur = {i, j};
        record.emplace(cur);
        visit[cur[0]][cur[1]] = 1;
        while (!record.empty()) {
            cur = record.front();
            grid[cur[0]][cur[1]] = -1;
            record.pop();
            for (vector<int> d : dire) {
                int x = cur[0] + d[0];
                int y = cur[1] + d[1];
                if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1 &&
                    visit[x][y] == 0) {
                    vector<int> next = {x, y};
                    record.emplace(next);
                    visit[x][y] = 1;
                    ++area;
                }
            }
        }
        return area;
    }
};