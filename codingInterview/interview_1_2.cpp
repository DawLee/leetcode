
/*
判定是否互为字符重排
easy   *
medium
hard
*/

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        unordered_map<char, int> record;
        for (const char &c : s1) {
            ++record[c];
        }
        for (const char &c : s2) {
            --record[c];
            if (record[c] < 0) {
                return false;
            }
        }
        return true;
    }
};