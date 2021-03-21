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

// 使用库函数
class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) {
            return res;
        }
        auto tmp = lower_bound(nums.begin(), nums.end(), target);
        if (tmp == nums.end() || nums[tmp - nums.begin()] != target) {
            return res;
        } else {
            res[0] = tmp - nums.begin();
        }
        res[1] =
            upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return res;
    }
};

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) {
            return res;
        }
        int left = bigEqualFirstNum(nums, target);
        if (left >= nums.size() || nums[left] != target) {
            return res;
        }
        cout << left << endl;
        res[0] = left;
        res[1] = bigEqualFirstNum(nums, target + 1) - 1;
        return res;
    }
    // 查找 大于等于/大于 target的第一个元素
    int bigEqualFirstNum(const vector<int> &vec, const int &target) {
        int left = 0;
        int right = vec.size();
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (vec[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};