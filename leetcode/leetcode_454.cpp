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
    unordered_map<int, int> ab;
    unordered_map<int, int> cd;
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                     vector<int> &D) {
        if (A.empty()) {
            return 0;
        }
        int res = 0;
        unordered_map<int, int> ab = recordMap(A, B);
        unordered_map<int, int> cd = recordMap(C, D);
        int tmp = 0;
        for (auto key : ab) {
            tmp = key.first;
            if (cd.find(-tmp) != cd.end()) {
                res += key.second * cd[-tmp];
            }
        }
        return res;
    }
    unordered_map<int, int> recordMap(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> record;
        int len = a.size();
        int tmp = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                tmp = a[i] + b[j];
                if (record.find(tmp) == record.end()) {
                    record.emplace(make_pair(tmp, 0));
                }
                ++record[tmp];
            }
        }
        return record;
    }
};