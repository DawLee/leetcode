
/*
数组中数字出现的次数
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
    vector<int> singleNumbers(vector<int> &nums) {
        int twoNum = getOneSingleNum(nums);
        int digit = getOneDigit(twoNum);
        int num1 = 0;
        int num2 = 0;
        for (const int &n : nums) {
            if (((n >> digit) & 1) == 0) {
                num1 ^= n;
            } else {
                num2 ^= n;
            }
        }
        return {num1, num2};
    }
    int getOneSingleNum(const vector<int> &nums) {
        int res = 0;
        for (const int &n : nums) {
            res ^= n;
        }
        return res;
    }
    int getOneDigit(int num) {
        int res = 0;
        while (((num >> res) & 1) == 0) {
            ++res;
        }
        return res;
    }
};