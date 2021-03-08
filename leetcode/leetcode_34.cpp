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
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) {
            return res;
        }
        res[0] = binarySearch(nums, target, true);
        res[1] = binarySearch(nums, target, false);
        return res;
    }
    int binarySearch(vector<int> &nums, int target, bool flag) {
        // flag = true,查找第一个target
        // flag = false,查找最后一个target
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;
        bool res = false;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                res = true;
                if (flag) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (!res) {
            return -1;
        } else if (!flag) {
            return max(0, left - 1);
        }
        return left;
    }
};