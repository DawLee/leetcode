/*
组合总和 II
easy
medium *
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

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
    void backtracking(const vector<int> &nums, int target, int start) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            res.emplace_back(path);
            return;
        }
        unordered_set<int> record;
        for (int i = start; i < nums.size(); ++i) {
            if (record.find(nums[i]) != record.end()) {
                continue;
            }
            record.emplace(nums[i]);
            path.emplace_back(nums[i]);
            target -= nums[i];
            backtracking(nums, target, i + 1);
            target += nums[i];
            path.pop_back();
        }
    }
};
