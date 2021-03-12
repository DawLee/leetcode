/*
N皇后
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
    unordered_set<int> col;
    unordered_set<int> sum;
    unordered_set<int> del;
    vector<vector<string>> res;
    vector<int> path;
    vector<vector<string>> solveNQueens(int n) {
        backtracking(n, 0);
        return res;
    }
    void backtracking(const int n, int row) {
        if (row == n) {
            res.emplace_back(getResStr(path));
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (col.find(i) != col.end() || sum.find(i + row) != sum.end() ||
                del.find(i - row) != del.end()) {
                continue;
            }
            col.emplace(i);
            sum.emplace(i + row);
            del.emplace(i - row);
            path.emplace_back(i);
            backtracking(n, row + 1);
            path.pop_back();
            col.erase(i);
            sum.erase(i + row);
            del.erase(i - row);
        }
    }
    vector<string> getResStr(vector<int> path) {
        int len = path.size();
        vector<string> resStr(len, "");
        string STR(len, '.');
        for (int i = 0; i < len; ++i) {
            string strTmp = STR;
            strTmp[path[i]] = 'Q';
            resStr[i] = strTmp;
        }
        return resStr;
    }
};