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
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res(2, 0);
        unordered_map<int, int> record;
        int len = nums.size();
        int tmp = 0;
        for (int i = 0; i < len; ++i) {
            tmp = target - nums[i];
            if (record.find(tmp) != record.end()) {
                res[0] = record[tmp];
                res[1] = i;
                return res;
            }
            record.insert(make_pair(nums[i], i));
        }
        return res;
    }
};