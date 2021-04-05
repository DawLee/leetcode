
/*
一次编辑
easy   *
medium
hard
*/

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    bool oneEditAway(string first, string second) {
        int len1 = first.size();
        int len2 = second.size();
        int sameLen = false;
        if (abs(len1 - len2) > 1) {
            return false;
        } else if (len1 == len2) {
            sameLen = true;
        }
        int flag = true;
        int index1 = 0;
        int index2 = 0;
        while (index1 < len1 && index2 < len2) {
            if (first[index1] == second[index2]) {
                ++index1;
                ++index2;
                continue;
            }

            if (!flag) {
                return false;
            }
            flag = false;

            if (len1 == len2) {
                ++index1;
                ++index2;
            } else if (len1 > len2) {
                ++index1;
            } else {
                ++index2;
            }
        }
        return true;
    }
};