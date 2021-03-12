/*
子集
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
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return res;
    }
    void backtracking(const vector<int> &nums, int start, vector<bool> &used) {
        res.emplace_back(path);
        for (int i = start; i < nums.size(); ++i) {
            if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            path.emplace_back(nums[i]);
            backtracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
};

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
    void backtracking(const vector<int> &nums, int start) {
        res.emplace_back(path);
        unordered_set<int> record;
        for (int i = start; i < nums.size(); ++i) {
            if (record.find(nums[i]) != record.end()) {
                continue;
            }
            record.emplace(nums[i]);
            path.emplace_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};