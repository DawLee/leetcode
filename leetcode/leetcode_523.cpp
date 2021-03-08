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
    bool checkSubarraySum(vector<int> &nums, int k) {
        int len = nums.size();
        if (len < 2) {
            return false;
        }
        unordered_map<int, int> record = {{0, -1}};
        int pre = 0;
        int tmp = 0;
        for (int i = 0; i < len; ++i) {
            tmp = pre + nums[i];
            tmp = (k == 0) ? tmp : (tmp % k);
            if (record.find(tmp) == record.end()) {
                record.emplace(make_pair(tmp, i));
            }
            if (i - record[tmp] > 1) {
                return true;
            }
            pre = tmp;
        }
        return false;
    }
};