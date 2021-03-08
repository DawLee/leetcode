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
    int subarraySum(vector<int> &nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        int res = 0;
        unordered_map<int, int> record = {{0, 1}};
        int len = nums.size();
        int pre = 0;
        int tmp = 0;
        for (int i = 0; i < len; ++i) {
            tmp = pre + nums[i];
            if (record.find(tmp - k) != record.end()) {
                res += record[tmp - k];
            }
            if (record.find(tmp) == record.end()) {
                record.emplace(make_pair(tmp, 0));
            }
            ++record[tmp];
            pre = tmp;
        }
        return res;
    }
};