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
    int leastBricks(vector<vector<int>> &wall) {
        if (wall.empty()) {
            return 0;
        }
        int len = wall.size();
        int res = 0;
        int width = 0;
        int tmp = 0;
        unordered_map<int, int> record;
        for (int i = 0; i < wall[0].size(); ++i) {
            width += wall[0][i];
            record.emplace(make_pair(width, 1));
        }
        for (int i = 1; i < len; ++i) {
            tmp = 0;
            for (int j = 0; j < wall[i].size(); ++j) {
                tmp += wall[i][j];
                if (record.find(tmp) == record.end()) {
                    record.emplace(tmp, 0);
                }
                ++record[tmp];
            }
        }
        record.erase(width);
        if (record.size() == 0) {
            return len;
        }
        for (auto key : record) {
            res = max(res, key.second);
        }
        res = len - res;
        return res;
    }
};