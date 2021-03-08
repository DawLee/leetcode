#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> record_st;
        unordered_map<char, char> record_ts;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (record_st.find(s[i]) == record_st.end()) {
                record_st.emplace(s[i], t[i]);
            }
            if (record_ts.find(t[i]) == record_ts.end()) {
                record_ts.emplace(t[i], s[i]);
            }
            if (record_st[s[i]] != t[i]) {
                return false;
            }
            if (record_ts[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};