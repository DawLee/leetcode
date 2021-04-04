
/*
左旋转字符串
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
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        reverseStr(s, 0, len - 1);
        reverseStr(s, 0, len - n - 1);
        reverseStr(s, len - n, len - 1);
        return s;
    }
    void reverseStr(string &s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};