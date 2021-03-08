/*
最长递增子序列
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

// 单调栈，递增栈
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = 1;
        stack<int> record;
        int recordSize = 1;
        record.emplace(nums[0]);
        int len = nums.size();
        for (int i = 1; i < len; ++i) {
            if (!record.empty() && record.top() > nums[i]) {
                recordSize = record.size();
                res = max(res, recordSize);
                while (!record.empty() && record.top() > nums[i]) {
                    record.pop();
                }
            }
            record.emplace(nums[i]);
        }
        recordSize = record.size();
        res = max(res, recordSize);
        return res;
    }
};