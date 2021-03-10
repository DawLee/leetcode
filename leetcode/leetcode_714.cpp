/*
无重叠区间
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
    int maxProfit(vector<int> &prices, int fee) {
        int res = 0;
        int len = prices.size();
        int minPrice = prices[0];
        for (int i = 1; i < len; ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] >= minPrice && prices[i] <= minPrice + fee) {
                continue;
            } else {
                res += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
            }
        }
        return res;
    }
};

// 动态规划
class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        int res = 0;
        int len = prices.size();
        vector<int> dp(2, 0);
        dp[1] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[0] = max(dp[0], prices[i] + dp[1] - fee);
            dp[1] = max(dp[1], dp[0] - prices[i]);
        }
        return dp[0];
    }
};
