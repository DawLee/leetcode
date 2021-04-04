
/*
股票的最大利润
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
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> dp(2, 0);
        dp[0] = -prices[0];
        for (const int &n : prices) {
            dp[0] = max(dp[0], -n);
            dp[1] = max(dp[1], n + dp[0]);
        }
        return dp[1];
    }
};