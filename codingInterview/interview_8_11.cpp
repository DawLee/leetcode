// coding Interview 8_11
// 硬币
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    int waysToChange(int n) {
        static constexpr int mod = 1000000007;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> coins = {1, 5, 10, 25};
        for (const int &coin : coins) {
            for (int i = 1; i <= n; ++i) {
                if (i - coin >= 0) {
                    dp[i] = (dp[i] + dp[i - coin]) % mod;
                }
            }
        }
        return dp[n];
    }
};
