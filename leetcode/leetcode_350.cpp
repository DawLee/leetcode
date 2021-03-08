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
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty()) {
            return res;
        }
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2) {
            swap(nums1, nums2);
            len1 = len2;
            len2 = nums2.size();
        }
        unordered_map<int, int> record;
        for (int i = 0; i < len1; ++i) {
            if (record.find(nums1[i]) == record.end()) {
                record.emplace(make_pair(nums1[i], 0));
            }
            ++record[nums1[i]];
        }
        for (int i = 0; i < len2; ++i) {
            if (record[nums2[i]] > 0) {
                res.emplace_back(nums2[i]);
                --record[nums2[i]];
            }
        }
        return res;
    }
};