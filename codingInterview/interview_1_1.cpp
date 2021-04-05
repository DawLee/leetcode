
/*
包含min函数的栈
easy   *
medium
hard
*/

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    bool isUnique(string astr) {
        int count = 0;
        int tmp = 0;
        for (const char &c : astr) {
            tmp = c - 'a';
            if (((count >> tmp) & 1) == 1) {
                return false;
            }
            count |= 1 << tmp;
        }
        return true;
    }
};