/*
分割等和子集
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
    bool canPartition(vector<int> &nums) {
        int len = nums.size();
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < len; ++i) {
            for (int j = sum; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                if (dp[j] == sum) {
                    return true;
                }
            }
        }
        return false;
    }
};
