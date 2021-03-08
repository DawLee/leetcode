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

// 二分
class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left / 2);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

// 遍历
class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty())
            return 0;
        if (nums[0] >= target)
            return 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == target)
                return i;
            if (nums[i] > target)
                return i;
        }
        return nums.size();
    }
};