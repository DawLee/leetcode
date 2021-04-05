// coding Interview 1_9
// 字符串轮转
// easy

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        s2 += s2;
        if (s2.find(s1) == s2.npos) {
            return false;
        }
        return true;
    }
};