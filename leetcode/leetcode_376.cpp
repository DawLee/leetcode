/*
摆动序列
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
    int wiggleMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }
        int res = 1;
        int preDiff = 0;
        int curDiff = 0;
        for (int i = 0; i < len - 1; ++i) {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff >= 0 && curDiff < 0) ||
                (preDiff <= 0 && curDiff > 0)) {
                ++res;
                preDiff = curDiff;
            }
        }
        return res;
    }
};