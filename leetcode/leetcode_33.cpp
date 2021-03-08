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
    int search(vector<int> &nums, int target) {
        int res = 0;
        int len = nums.size();
        int min = findMin(nums);
        // cout << min << endl;
        res = binaryFind(nums, 0, min - 1, target);
        if (min == 0 || nums[0] > target) {
            return binaryFind(nums, min, len - 1, target);
        } else {
            return binaryFind(nums, 0, min - 1, target);
        }
    }
    int findMin(vector<int> &nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int binaryFind(vector<int> &nums, int left, int right, int target) {
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};