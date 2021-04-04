/*
扑克牌中的顺子
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
    bool isStraight(vector<int> &nums) {
        unordered_set<int> record;
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        int zeros = 0;
        for (const int &n : nums) {
            if (n == 0) {
                continue;
            }
            if (record.find(n) != record.end()) {
                return false;
            }
            record.emplace(n);
            maxNum = max(maxNum, n);
            minNum = min(minNum, n);
        }
        return maxNum - minNum < 5;
    }
};