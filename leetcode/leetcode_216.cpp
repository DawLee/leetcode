/*
组合总和 III
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
    vector<vector<int>> res;
    vector<int> path;
    int sum;
    vector<vector<int>> combinationSum3(int k, int n) {
        sum = 0;
        backtracking(k, n, 1);
        return res;
    }
    void backtracking(int k, int n, int start) {
        if (sum > n) {
            return;
        } else if (sum == n && path.size() == k) {
            res.emplace_back(path);
        }
        for (int i = start; i <= 9 - k + path.size() + 1; ++i) {
            path.emplace_back(i);
            sum += i;
            backtracking(k, n, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
};

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return res;
    }
    void backtracking(int k, int n, int start) {
        if (n < 0) {
            return;
        } else if (path.size() == k) {
            if (n == 0) {
                res.emplace_back(path);
            }
            return;
        }
        for (int i = start; i <= 9 - k + path.size() + 1; ++i) {
            path.emplace_back(i);
            n -= i;
            backtracking(k, n, i + 1);
            n += i;
            path.pop_back();
        }
    }
};