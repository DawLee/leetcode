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
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int len = nums.size();
        int resTmp = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            left = i + 1;
            right = len - 1;
            while (left < right) {
                resTmp = nums[i] + nums[left] + nums[right];
                res = abs(target - resTmp) < abs(target - res) ? resTmp : res;
                if (resTmp == target) {
                    return target;
                } else if (resTmp < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};