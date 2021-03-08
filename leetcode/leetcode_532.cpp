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
    int findPairs(vector<int> &nums, int k) {
        int res = 0;
        int tmp = 0;
        unordered_map<int, int> record;
        int len = nums.size();
        for (auto num : nums) {
            if (record.find(num) == record.end()) {
                record.insert(make_pair(num, 1));
            } else {
                ++record[num];
            }
        }
        if (k == 0) {
            for (auto key : record) {
                if (key.second > 1) {
                    ++res;
                }
            }
            return res;
        }
        for (auto key : record) {
            tmp = key.first;
            if (record.find(tmp + k) != record.end()) {
                ++res;
            }
            if (record.find(tmp - k) != record.end()) {
                ++res;
            }
        }
        return res / 2;
    }
};