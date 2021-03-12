/*
重新安排行程
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
    unordered_map<string, map<string, int>> record;
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (vector<string> ticket : tickets) {
            ++record[ticket[0]][ticket[1]];
        }
        int len = tickets.size();
        vector<string> res;
        res.emplace_back("JFK");
        backtracking(len, res);
        return res;
    }
    bool backtracking(const int len, vector<string> &path) {
        if (path.size() == len + 1) {
            return true;
        }
        for (pair<const string, int> &ticket : record[path.back()]) {
            if (ticket.second > 0) {
                --ticket.second;
                path.emplace_back(ticket.first);
                if (backtracking(len, path)) {
                    return true;
                }
                path.pop_back();
                ++ticket.second;
            }
        }
        return false;
    }
};