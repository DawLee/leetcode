/*
无重叠区间
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
    static bool cmp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return 0;
        }
        int res = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int right = intervals[0][1];
        int len = intervals.size();
        for (int i = 1; i < len; ++i) {
            cout << intervals[i][0] << ',' << intervals[i][1] << endl;
            cout << right << endl;
            if (intervals[i][0] == intervals[i - 1][0]) {
                ++res;
            } else {
                if (intervals[i][0] < right) {
                    ++res;
                    right = min(right, intervals[i][1]);
                } else {
                    right = intervals[i][1];
                }
            }
            cout << res << endl;
        }
        return res;
    }
};