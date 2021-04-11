// coding Interview 8_9
// 括号
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    vector<string> res;
    string path;
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return res;
        }
        int left = 0;
        int right = 0;
        path.resize(2 * n);
        backtracking(n, 0, 0, 0);
        return res;
    }
    void backtracking(const int n, int index, int left, int right) {
        if (index == (n << 1)) {
            res.emplace_back(path);
            return;
        }
        if (left < n) {
            path[index] = '(';
            backtracking(n, index + 1, left + 1, right);
        }
        if (right < left) {
            path[index] = ')';
            backtracking(n, index + 1, left, right + 1);
        }
    }
};