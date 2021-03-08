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
    vector<string> record = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    vector<string> findWords(vector<string> &words) {
        vector<string> res;
        int index = 0;
        int len = words.size();
        for (auto str : words) {
            index = whitchDict(str);
            if (isRight(record[index], str)) {
                res.push_back(str);
            }
        }
        return res;
    }
    bool isRight(string dict, string word) {
        int len = word.size();
        for (auto c : word) {
            if (dict.find(tolower(c)) == string::npos) {
                return false;
            }
        }
        return true;
    }
    int whitchDict(string str) {
        int recordSize = record.size();
        for (int i = 0; i < recordSize; ++i) {
            if (record[i].find(tolower(str[0])) != string::npos) {
                return i;
            }
        }
        return 0;
    }
};