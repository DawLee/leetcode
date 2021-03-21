/*
扫雷游戏
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

// DFS
class Solution {
  public:
    vector<vector<int>> dire = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    vector<vector<int>> visit;
    vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                     vector<int> &click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        if (board[click[0]][click[1]] >= '1' &&
            board[click[0]][click[1]] <= '9') {
            return board;
        }
        vector<int> tmp(board[0].size(), 0);
        for (int i = 0; i < board.size(); ++i) {
            visit.emplace_back(tmp);
        }
        dfs(board, click);
        return board;
    }
    void dfs(vector<vector<char>> &board, vector<int> &click) {
        if (click[0] < 0 || click[0] >= board.size() || click[1] < 0 ||
            click[1] >= board[0].size() || visit[click[0]][click[1]] == 1 ||
            board[click[0]][click[1]] == 'M') {
            return;
        }
        visit[click[0]][click[1]] = 1;
        int mines = 0;
        for (vector<int> d : dire) {
            int x = click[0] + d[0];
            int y = click[1] + d[1];
            vector<int> next = {x, y};
            mines += getMines(board, next);
        }
        if (mines == 0) {
            board[click[0]][click[1]] = 'B';
            for (vector<int> d : dire) {
                int x = click[0] + d[0];
                int y = click[1] + d[1];
                vector<int> next = {x, y};
                dfs(board, next);
            }
        } else {
            board[click[0]][click[1]] = mines + '0';
        }
    }
    int getMines(const vector<vector<char>> &board, vector<int> &click) {
        if (click[0] < 0 || click[0] >= board.size() || click[1] < 0 ||
            click[1] >= board[0].size()) {
            return 0;
        }
        if (board[click[0]][click[1]] == 'M') {
            return 1;
        }
        return 0;
    }
};

// BFS
class Solution {
  public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                     vector<int> &click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        if (board[click[0]][click[1]] >= '1' &&
            board[click[0]][click[1]] <= '9') {
            return board;
        }
        vector<vector<int>> dire = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                    {0, 1},   {1, -1}, {1, 0},  {1, 1}};
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> visit(row, vector<int>(col, 0));
        queue<vector<int>> record;
        record.emplace(click);
        visit[click[0]][click[1]] = 1;
        vector<int> cur;
        while (!record.empty()) {
            cur = record.front();
            record.pop();
            cout << cur[0] << ',' << cur[1] << endl;
            int mines = 0;
            for (vector<int> d : dire) {
                int x = cur[0] + d[0];
                int y = cur[1] + d[1];
                vector<int> next = {x, y};
                mines += getMines(board, next);
            }
            cout << mines << endl;
            if (mines == 0) {
                board[cur[0]][cur[1]] = 'B';
                for (vector<int> d : dire) {
                    int x = cur[0] + d[0];
                    int y = cur[1] + d[1];
                    if (x >= 0 && x < row && y >= 0 && y < col &&
                        board[x][y] == 'E' && visit[x][y] == 0) {
                        vector<int> next = {x, y};
                        record.emplace(next);
                        visit[x][y] = 1;
                    }
                }
            } else {
                board[cur[0]][cur[1]] = mines + '0';
            }
        }
        return board;
    }
    int getMines(const vector<vector<char>> &board, vector<int> &click) {
        if (click[0] < 0 || click[0] >= board.size() || click[1] < 0 ||
            click[1] >= board[0].size()) {
            return 0;
        }
        if (board[click[0]][click[1]] == 'M') {
            return 1;
        }
        return 0;
    }
};