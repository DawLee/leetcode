// coding Interview 8_7
// 无重复字符串的排列组合
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    vector<string> res;
    string path;
    vector<bool> used;
    vector<string> permutation(string S) {
        if (S.empty()) {
            return res;
        }
        path = "";
        int len = S.size();
        used.resize(len, false);
        backtracking(S, len);
        return res;
    }
    void backtracking(const string S, const int len) {
        if (path.size() == len) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (used[i]) {
                continue;
            }
            path += S[i];
            used[i] = true;
            backtracking(S, len);
            used[i] = false;
            path.pop_back();
        }
    }
};