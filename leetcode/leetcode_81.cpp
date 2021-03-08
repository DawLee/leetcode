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
    bool search(vector<int> &nums, int target) {
        int len = nums.size();
        int res = 0;
        int indexMin = findMin(nums);
        if (nums[0] == nums[indexMin] || nums[0] <= target) {
            return binaryFindWithRepeatNum(nums, 0, indexMin, target);
        } else {
            return binaryFindWithRepeatNum(nums, indexMin, len - 1, target);
        }
    }
    bool binaryFindWithRepeatNum(vector<int> &nums, int left, int right,
                                 int target) {
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[left] == nums[right]) {
                return false;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
    int findMin(vector<int> &nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            // 当左右两边相等时，若都大于等于mid值，同时向中间缩小范围
            if (nums[left] == nums[right] && nums[mid] <= nums[left]) {
                ++left;
                --right;
            } else if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};