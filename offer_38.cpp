/*
序列化二叉树
easy
medium
hard   *
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
    vector<string> res;
    vector<bool> used;
    string path;
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        int len = s.size();
        path = "";
        used.resize(len, false);
        backtracking(s, len);
        return res;
    }
    void backtracking(const string &s, const int len) {
        if (path.size() == len) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1] || used[i]) {
                continue;
            }
            path += s[i];
            used[i] = true;
            backtracking(s, len);
            used[i] = false;
            path.pop_back();
        }
    }
};