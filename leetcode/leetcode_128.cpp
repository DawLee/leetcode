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
    int longestConsecutive(vector<int> &nums) {
        int res = 0;
        int resTmp = 0;
        int tmp = 0;
        unordered_set<int> record;
        for (auto i : nums) {
            if (record.find(i) == record.end()) {
                record.insert(i);
            }
        }
        for (auto i : nums) {
            if (record.find(i - 1) != record.end()) {
                continue;
            }
            resTmp = i;
            while (record.find(resTmp) != record.end()) {
                ++resTmp;
                ++tmp;
            }
            res = res > tmp ? res : tmp;
            tmp = 0;
        }
        return res;
    }
};
