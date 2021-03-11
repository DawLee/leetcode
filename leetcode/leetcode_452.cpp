/*
用最少数量的箭引爆气球
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
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        int res = 1;
        int len = points.size();
        sort(points.begin(), points.end());
        int target = points[0][1];
        for (int i = 1; i < len; ++i) {
            if (points[i][0] > target) {
                ++res;
                target = points[i][1];
            } else {
                target = min(target, points[i][1]);
            }
        }
        return res;
    }
};