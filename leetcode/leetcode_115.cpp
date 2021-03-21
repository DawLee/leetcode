/*
不同的子序列
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
    int numDistinct(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if (s.empty() || lens < lent) {
            return 0;
        }
        vector<long> dp(lent, 0);
        unordered_map<char, vector<int>> record;
        for (int i = 0; i < lent; ++i) {
            record[t[i]].emplace_back(i);
        }
        int k = 0;
        for (int i = 0; i < lens; ++i) {
            char c = s[i];
            for (int j = record[c].size() - 1; j >= 0; --j) {
                k = record[c][j];
                if (k == 0) {
                    ++dp[k];
                } else {
                    dp[k] += dp[k - 1];
                }
            }
        }
        return dp[lent - 1];
    }
};