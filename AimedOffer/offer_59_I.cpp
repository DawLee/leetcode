
/*
滑动窗口的最大值
easy
medium
hard   *
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
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        if (nums.empty()) {
            return res;
        }
        int len = nums.size();
        deque<int> record;
        int i = 0;
        while (i < k) {
            while (!record.empty() && nums[record.back()] < nums[i]) {
                record.pop_back();
            }
            record.emplace_back(i);
            ++i;
        }
        res.emplace_back(nums[record.front()]);
        while (i < len) {
            if (i - record.front() >= k) {
                record.pop_front();
            }
            while (!record.empty() && nums[record.back()] < nums[i]) {
                record.pop_back();
            }
            record.emplace_back(i);
            res.emplace_back(nums[record.front()]);
            ++i;
        }
        return res;
    }
};