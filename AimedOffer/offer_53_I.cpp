
/*
在排序数组中查找数字 I
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

// 库函数
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        int first =
            lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (first == len) {
            return 0;
        }
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return last - first;
    }
};

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        int first = binarySearchBigEqualIndex(nums, target);
        if (first >= len || nums[first] != target) {
            return 0;
        }
        int last = binarySearchBigEqualIndex(nums, target + 1) - 1;
        return last - first;
    }
    int binarySearchBigEqualIndex(const vector<int> &nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        int left = 0;
        int right = len;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};