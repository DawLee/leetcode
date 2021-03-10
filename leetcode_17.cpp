/*
电话号码的字母组合
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
    const vector<string> record = {"",    "",    "abc",  "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string path;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }
        path = "";
        backtracking(digits, 0);
        return res;
    }
    void backtracking(const string &digits, int index) {
        if (index == digits.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < record[digits[index] - '0'].size(); ++i) {
            path += record[digits[index] - '0'][i];
            backtracking(digits, index + 1);
            path.erase(path.end() - 1);
        }
    }
};
