#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
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
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int len = nums.size();
        unordered_map<int, int> record;
        for (int i = 0; i < len; ++i) {
            if (record.find(nums[i]) == record.end()) {
                record.emplace(make_pair(nums[i], i));
            } else {
                if (i - record[nums[i]] <= k) {
                    return true;
                }
                record[nums[i]] = i;
            }
        }
        return false;
    }
};