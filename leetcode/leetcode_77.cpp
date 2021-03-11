/*
组合
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
    vector<int> tmp;
    vector<vector<int>> combine(int n, int k) {
        if (k > n) {
            return res;
        }
        backtracking(n, k, 1);
        return res;
    }
    void backtracking(int n, int k, int i) {
        if (tmp.size() == k) {
            res.emplace_back(tmp);
            return;
        }
        for (int j = i; j <= n - k + tmp.size() + 1; ++j) {
            tmp.emplace_back(j);
            backtracking(n, k, j + 1);
            tmp.pop_back();
        }
    }
};