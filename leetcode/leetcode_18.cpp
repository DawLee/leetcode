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
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int cd = 0;
        for (int a = 0; a < len - 3; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }
            for (int b = a + 1; b < len; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }
                int c = b + 1;
                int d = len - 1;
                int cd = target - nums[a] - nums[b];
                while (c < d) {
                    if (nums[c] + nums[d] == cd) {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c < d && nums[c + 1] == nums[c]) {
                            ++c;
                        }
                        while (c < d && nums[d - 1] == nums[d]) {
                            --d;
                        }
                        ++c;
                        --d;
                    } else if (nums[c] + nums[d] < cd) {
                        ++c;
                    } else {
                        --d;
                    }
                }
            }
        }
        return res;
    }
};