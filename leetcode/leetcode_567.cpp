/*
字符串的排列
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
    bool checkInclusion(string s1, string s2) {
        int ALPHA = 26;
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) {
            return false;
        }
        vector<int> r1(ALPHA, 0);
        for (int i = 0; i < len1; ++i) {
            ++r1[s1[i] - 'a'];
        }
        vector<int> r2(r1);
        int left = 0;
        int right = 0;
        while (right < len2) {
            while (right < len2 && r2[s2[right] - 'a'] > 0) {
                --r2[s2[right] - 'a'];
                ++right;
            }
            if (right - left == len1) {
                return true;
            }
            if (right == len2) {
                return false;
            }
            while (s2[left] != s2[right]) {
                ++r2[s2[left] - 'a'];
                ++left;
            }
            ++left;
            ++right;
        }
        return false;
    }
};