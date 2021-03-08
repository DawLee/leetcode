/*
最长连续递增序列
easy    *
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
    int findLengthOfLCIS(vector<int> &nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }
        int res = 0;
        int left = 0;
        int right = 1;
        while (right < len) {
            while (right < len && nums[right] > nums[right - 1]) {
                ++right;
            }
            res = res > (right - left) ? res : (right - left);
            left = right;
            ++right;
        }
        return res;
    }
};