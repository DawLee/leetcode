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
    vector<string> findRestaurant(vector<string> &list1,
                                  vector<string> &list2) {
        vector<string> res;
        int len1 = list1.size();
        int len2 = list2.size();
        int len = max(len1, len2);
        int m = INT_MAX;
        unordered_map<string, int> record1;
        unordered_map<string, int> record2;
        for (int i = 0; i < len; ++i) {
            if (i < len1) {
                if (record1.find(list1[i]) == record1.end()) {
                    record1.emplace(make_pair(list1[i], i));
                }
                if (record2.find(list1[i]) != record2.end()) {
                    if (m > record2[list1[i]] + i) {
                        res.clear();
                    }
                    if (m >= record2[list1[i]] + i) {
                        res.push_back(list1[i]);
                        m = record2[list1[i]] + i;
                    }
                }
            }
            if (i < len2) {
                if (record2.find(list2[i]) == record2.end()) {
                    record2.emplace(make_pair(list2[i], i));
                }
                if (record1.find(list2[i]) != record1.end()) {
                    if (m > record1[list2[i]] + i) {
                        res.clear();
                    }
                    if (m >= record1[list2[i]] + i) {
                        res.push_back(list2[i]);
                        m = record1[list2[i]] + i;
                    }
                }
            }
            if (m <= i && !res.empty()) {
                return res;
            }
        }
        return res;
    }
};