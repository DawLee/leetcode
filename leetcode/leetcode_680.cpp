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
    bool validPalindrome(string s) {
        if (s.empty()) {
            return false;
        }
        int len = s.size();
        int left = 0;
        int right = len - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            } else {
                break;
            }
        }
        if (left - right >= 0) {
            return true;
        }
        return isHuiwen(s, left + 1, right) || isHuiwen(s, left, right - 1);
    }
    bool isHuiwen(string str, int left, int right) {
        while (left < right) {
            if (str[left] == str[right]) {
                ++left;
                --right;
            } else {
                return false;
            }
        }
        return true;
    }
};