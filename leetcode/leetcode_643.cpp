/*
子数组最大平均数 I
easy    *
medium
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
    double findMaxAverage(vector<int> &nums, int k) {
        int res = getSumKnum(nums, k);
        int len = nums.size();
        int tmp = 0;
        int pre = res;
        for (int i = 1; i < len - k + 1; ++i) {
            tmp = pre - nums[i - 1] + nums[i + k - 1];
            res = res > tmp ? res : tmp;
            pre = tmp;
        }
        return (double)res / k;
    }
    int getSumKnum(vector<int> &nums, int k) {
        int res = 0;
        for (int i = 0; i < k; ++i) {
            res += nums[i];
        }
        return res;
    }
};