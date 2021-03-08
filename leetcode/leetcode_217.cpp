#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        set<int> record;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (record.find(nums[i]) != record.end()) {
                return false;
            }
            record.insert(nums[i]);
        }
        return true;
    }
};