/*
重复的DNA序列
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
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int L = 10;
        int len = s.size();
        if (len < L) {
            return res;
        }
        unordered_map<string, int> record;
        string tmp = "";
        for (int i = 0; i < len - L + 1; ++i) {
            tmp = s.substr(i, L);
            if (record.find(tmp) == record.end()) {
                record.emplace(make_pair(tmp, 0));
            } else if (record[tmp] == 1) {
                res.emplace_back(tmp);
            }
            ++record[tmp];
        }
        return res;
    }
};