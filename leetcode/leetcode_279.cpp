/*
完全平方数
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
    int numSquares(int n) {
        vector<int> nums;
        int tmp = 0;
        int i = 1;
        while (true) {
            tmp = i * i;
            if (tmp <= n) {
                nums.emplace_back(tmp);
            } else {
                break;
            }
            ++i;
        }
        int len = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (auto num : nums) {
            for (int i = 1; i <= n; ++i) {
                if (i >= num && dp[i - num] < INT_MAX) {
                    dp[i] = min(dp[i], dp[i - num] + 1);
                }
            }
        }
        return dp[n];
    }
};