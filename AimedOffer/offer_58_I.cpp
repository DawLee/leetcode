
/*
翻转单词顺序
easy   *
medium
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
    string reverseWords(string s) {
        string res = removeStrMoreSpace(s);
        int len = res.size();
        reverseStr(res, 0, len - 1);
        return reverseWordInStr(res, len);
    }
    string removeStrMoreSpace(const string &s) {
        string res = "";
        for (const char &c : s) {
            if (c == ' ' && (res.empty() || res.back() == ' ')) {
                continue;
            }
            res += c;
        }
        if (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }
    void reverseStr(string &s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
    string reverseWordInStr(string &s, const int len) {
        int left = 0;
        int right = 0;
        for (; right < len; ++right) {
            if (s[right] == ' ') {
                reverseStr(s, left, right - 1);
                left = right + 1;
            }
        }
        reverseStr(s, left, right - 1);
        return s;
    }
};