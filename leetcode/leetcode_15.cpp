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
  private:
    vector<vector<int>> res;

  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int len = nums.size();
        if (len < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < len - 2) {
            setRes(nums, len, i);
            ++i;
            while (i < len && nums[i] == nums[i - 1]) {
                ++i;
            }
        }
        return res;
    }
    void setRes(vector<int> &nums, int len, int i) {
        vector<int> resTmp = {nums[i], 0, 0};
        int left = i + 1;
        int right = len - 1;
        int tmp = -nums[i];
        while (left < right) {
            if (nums[left] + nums[right] == tmp) {
                resTmp[1] = nums[left];
                resTmp[2] = nums[right];
                res.emplace_back(resTmp);
                ++left;
                --right;
                while (left < len && nums[left] == nums[left - 1]) {
                    ++left;
                }
                while (right >= 0 && nums[right] == nums[right + 1]) {
                    --right;
                }
            } else if (nums[left] + nums[right] < tmp) {
                ++left;
                while (left < len && nums[left] == nums[left - 1]) {
                    ++left;
                }
            } else {
                --right;
                while (right >= 0 && nums[right] == nums[right + 1]) {
                    --right;
                }
            }
        }
    }
};