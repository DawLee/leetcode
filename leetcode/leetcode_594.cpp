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
    unordered_map<int, int> record;
    int findLHS(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int res = 0;
        int tmp1 = 0;
        int tmp2 = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            creatMapNum(nums[i] - 1);
            creatMapNum(nums[i]);
            creatMapNum(nums[i] + 1);
            ++record[nums[i]];
            tmp1 = getTwoNumLHS(nums[i], nums[i] - 1);
            tmp2 = getTwoNumLHS(nums[i], nums[i] + 1);
            res = max(res, max(tmp1, tmp2));
        }
        return res;
    }
    void creatMapNum(int num) {
        if (record.find(num) == record.end()) {
            record.emplace(make_pair(num, 0));
        }
    }
    int getTwoNumLHS(int num1, int num2) {
        if (record[num2] == 0) {
            return 0;
        }
        return record[num1] + record[num2];
    }
};