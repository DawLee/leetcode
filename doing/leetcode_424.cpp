/*
替换后的最长重复字符
easy
medium  *
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
    int ALPHA = 26;
    int characterReplacement(string s, int k) {
        int len = s.size();
        if (len <= k) {
            return len;
        }
        s += 'a'; //哨兵
        int res = 0;
        char c = 'a';
        int tmp = 0;
        int left = 0;
        int right = k;
        while (right < len) {
            left = right;
            c = s[left];
            while (right < len && s[right] == s[right + 1]) {
                ++right;
            }
            while (left > 0 && tmp <= k) {
                if (s[left] != c) {
                    ++tmp;
                }
                --left;
            }
            res = res > (right - left) ? res : right - left;
            tmp = 0;
        }
        return res;
    }
};