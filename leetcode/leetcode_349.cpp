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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        unordered_set<int> record;
        unordered_set<int> resRecord;
        int len = nums1.size();
        for (int i = 0; i < len; ++i) {
            if (record.find(nums1[i]) == record.end()) {
                record.insert(nums1[i]);
            }
        }
        len = nums2.size();
        for (int i = 0; i < len; ++i) {
            if (record.find(nums2[i]) != record.end() &&
                resRecord.find(nums2[i]) == resRecord.end()) {
                res.push_back(nums2[i]);
                resRecord.insert(nums2[i]);
            }
        }
        return res;
    }
};
