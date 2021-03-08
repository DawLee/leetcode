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
    bool wordPattern(string pattern, string s) {
        if (pattern.empty() || s.empty()) {
            return false;
        }
        vector<string> words = getWords(s);
        unordered_map<char, string> record;
        unordered_set<string> checkDict;
        int len = pattern.size();
        int lenwords = words.size();
        if (len != lenwords) {
            return false;
        }
        for (int i = 0; i < len; ++i) {
            if (record.find(pattern[i]) == record.end()) {
                record.insert(make_pair(pattern[i], words[i]));
            } else {
                if (record[pattern[i]] != words[i]) {
                    return false;
                }
            }
        }
        for (auto key : record) {
            if (checkDict.find(key.second) != checkDict.end()) {
                return false;
            }
            checkDict.insert(key.second);
        }
        return true;
    }
    vector<string> getWords(string s) {
        vector<string> words;
        string tmp = "";
        for (auto c : s) {
            if (c != ' ') {
                tmp += c;
            } else {
                words.emplace_back(tmp);
                tmp = "";
            }
        }
        if (tmp != "") {
            words.emplace_back(tmp);
        }
        return words;
    }
};