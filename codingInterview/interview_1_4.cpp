
/*
回文排列
easy   *
medium
hard
*/

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> record;
        for (const char &c : s) {
            if (record.find(c) == record.end()) {
                record.emplace(c);
            } else {
                record.erase(c);
            }
        }
        return record.size() <= 1;
    }
};