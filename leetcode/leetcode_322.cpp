/*
零钱兑换
easy
medium  *
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

// 动态规划
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        int len = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (auto coin : coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i >= coin && dp[i - coin] < INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        int res = dp[amount] == INT_MAX ? -1 : dp[amount];
        return res;
    }
};

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        int res = -1;
        int len = coins.size();
        int *record = new int[amount + 1];
        record[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            record[i] = INT_MAX;
            for (auto j : coins) {
                if (i >= j && record[i - j] != INT_MAX) {
                    record[i] = min(record[i - j] + 1, record[i]);
                }
            }
        }
        res = record[amount] == INT_MAX ? -1 : record[amount];
        delete[] record;
        return res;
    }
};
