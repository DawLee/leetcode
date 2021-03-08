/*
目标和
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
    int findTargetSumWays(vector<int> &nums, int S) {
        int res = 0;
        int len = nums.size();
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        int target = (sum + S) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < len; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};