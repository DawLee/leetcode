/*
最大子序和
easy   *
medium
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
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = nums[0];
        int pre = nums[0];
        int cur = 0;
        int len = nums.size();
        for (int i = 1; i < len; ++i) {
            cur = max(pre + nums[i], nums[i]);
            res = max(res, cur);
            pre = cur;
        }
        return res;
    }
};