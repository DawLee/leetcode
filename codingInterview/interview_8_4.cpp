// coding Interview 8_4
// 幂集
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.empty()) {
            return res;
        }
        int len = nums.size();
        backtracking(nums, len, 0);
        return res;
    }
    void backtracking(const vector<int> &nums, const int len, int start) {
        res.emplace_back(path);
        for (int i = start; i < len; ++i) {
            path.emplace_back(nums[i]);
            backtracking(nums, len, i + 1);
            path.pop_back();
        }
    }
};