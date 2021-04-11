// coding Interview 8_2
// 迷路机器人
// medium

#include "leetcode.h"
using namespace std;

// 动态规划
class Solution {
  public:
    vector<vector<int>> path;
    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1 ||
            obstacleGrid[row - 1][col - 1]) {
            return path;
        }
        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                if (i == row - 1 && j == col - 1 || obstacleGrid[i][j] == 1) {
                    continue;
                }
                if (i == row - 1) {
                    obstacleGrid[i][j] = obstacleGrid[i][j + 1];
                } else if (j == col - 1) {
                    obstacleGrid[i][j] = obstacleGrid[i + 1][j];
                } else {
                    obstacleGrid[i][j] =
                        obstacleGrid[i][j + 1] && obstacleGrid[i + 1][j];
                }
            }
        }
        if (obstacleGrid[0][0] == 1) {
            return path;
        }
        dfs(obstacleGrid, row, col, 0, 0);
        return path;
    }
    void dfs(const vector<vector<int>> &obstacleGrid, const int row,
             const int col, int r, int c) {
        path.push_back({r, c});
        if (r == row - 1 && c == col - 1) {
            return;
        }
        if (c + 1 < col && obstacleGrid[r][c + 1] == 0) {
            dfs(obstacleGrid, row, col, r, c + 1);
        } else if (r + 1 < row && obstacleGrid[r + 1][c] == 0) {
            dfs(obstacleGrid, row, col, r + 1, c);
        }
    }
};

// 回溯法
class Solution {
  public:
    vector<vector<int>> path;
    vector<vector<int>> dire;
    vector<vector<bool>> visit;
    int direSize;
    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty()) {
            return path;
        }
        dire.push_back({0, 1});
        dire.push_back({1, 0});
        direSize = dire.size();
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        visit.resize(row, vector<bool>(col, false));
        if (obstacleGrid[row - 1][col - 1] == 1) {
            return path;
        }
        path.push_back({0, 0});
        if (backtracking(obstacleGrid, row, col, 0, 0)) {
            return path;
        }
        path.clear();
        return path;
    }
    bool backtracking(vector<vector<int>> &obstacleGrid, const int row,
                      const int col, int r, int c) {
        if (r < 0 || r >= row || c < 0 || c >= col || obstacleGrid[r][c] == 1 ||
            visit[r][c]) {
            return false;
        }
        if (r == row - 1 && c == col - 1) {
            return true;
        }
        visit[r][c] = true;
        for (int i = 0; i < dire.size(); ++i) {
            vector<int> next = {r + dire[i][0], c + dire[i][1]};
            path.emplace_back(next);
            if (backtracking(obstacleGrid, row, col, next[0], next[1])) {
                return true;
            }
            path.pop_back();
        }
        return false;
    }
};