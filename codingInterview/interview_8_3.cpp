// coding Interview 8_3
// 迷路机器人
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    int res = INT_MAX;
    int findMagicIndex(vector<int> &nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        binaryFind(nums, 0, len);
        return res == INT_MAX ? -1 : res;
    }
    void binaryFind(const vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        if (res <= left) {
            return;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == mid) {
            res = min(res, mid);
            right = mid;
            binaryFind(nums, left, mid);
        } else {
            binaryFind(nums, left, mid);
            binaryFind(nums, mid + 1, right);
        }
    }
};