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
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        int len = nums.size();
        int index = min(len, k);
        bool flag = true;
        int left = 0;
        int right = 0;
        for (; right < index; ++right) {
            if (pushListNum(nums, left, right, t)) {
                return true;
            }
        }
        for (int i = right; i < len; ++i) {
            if (pushListNum(nums, left, right, t)) {
                return true;
            }
            ++left;
            ++right;
        }
        return false;
    }
    bool pushListNum(const vector<int> &nums, const int left, const int right,
                     const int t) {
        for (int i = left; i < right; ++i) {
            if (abs(nums[right] - nums[i]) <= t) {
                return true;
            }
        }
        return false;
    }
};