
/*
和为s的连续正数序列
easy   *
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
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;

        int left = 1;
        int right = 1;
        int sum = 1;
        while (right < target) {
            if (sum == target) {
                vector<int> tmp = getVector(left, right);
                res.emplace_back(tmp);
                sum -= left;
                ++left;
            } else if (sum < target) {
                ++right;
                sum += right;
            } else {
                sum -= left;
                ++left;
            }
        }
        return res;
    }
    vector<int> getVector(int left, int right) {
        vector<int> tmp(right - left + 1);
        for (int i = left; i <= right; ++i) {
            tmp[i - left] = i;
        }
        return tmp;
    }
};