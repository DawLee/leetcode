/*
一和零
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
    int findMaxForm(vector<string> &strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        pair<int, int> tmp(0, 0);
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < len; ++i) {
            tmp = getZeroOneNum(strs[i]);
            zeros = tmp.first;
            ones = tmp.second;
            for (int j = m; j >= 0; j--) {
                for (int k = n; k >= 0; --k) {
                    if (zeros <= j && ones <= k) {
                        dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
    pair<int, int> getZeroOneNum(string str) {
        pair<int, int> res(0, 0);
        int len = str.size();
        for (char c : str) {
            if (c == '0') {
                ++res.first;
            }
        }
        res.second = len - res.first;
        return res;
    }
};