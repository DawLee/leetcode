/*
最长公共子序列
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
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<int> dp(len1 + 1, 0);
        int pre = 0;
        int cur = 0;
        // text2 循环
        for (int i = 0; i < len2; ++i) {
            // text1 循环
            pre = 0;
            for (int j = 1; j <= len1; ++j) {
                int cur = dp[j];
                if (text1[j - 1] == text2[i]) {
                    dp[j] = pre + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = cur;
            }
        }
        return dp[len1];
    }
};