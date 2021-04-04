/*
第一个只出现一次的字符
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
    char firstUniqChar(string s) {
        vector<int> record(26, 0);
        queue<char> order;
        int len = s.size();
        for (const char &c : s) {
            if (record[c - 'a'] == 0) {
                order.emplace(c);
            }
            ++record[c - 'a'];
        }
        char res = ' ';
        while (!order.empty()) {
            if (record[order.front() - 'a'] == 1) {
                res = order.front();
                break;
            }
            order.pop();
        }
        return res;
    }
};