/*
下一个更大元素II
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
    vector<int> nextGreaterElements(vector<int> &nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        stack<int> record;
        for (int i = 0; i < len; ++i) {
            if (record.empty() || nums[record.top()] >= nums[i]) {
                record.emplace(i);
                continue;
            }
            while (!record.empty() && nums[record.top()] < nums[i]) {
                res[record.top()] = nums[i];
                record.pop();
            }
            record.emplace(i);
        }
        if (!record.empty()) {
            for (int i = 0; i < len; ++i) {
                while (!record.empty() && nums[record.top()] < nums[i]) {
                    res[record.top()] = nums[i];
                    record.pop();
                }
                if (record.empty()) {
                    break;
                }
            }
        }
        return res;
    }
};