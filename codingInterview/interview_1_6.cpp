
/*
字符串压缩
easy   *
medium
hard
*/

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    string compressString(string S) {
        string res = "";
        int len = S.size();
        int left = 0;
        int right = 0;
        int count = 0;
        while (right < len) {
            while (right < len && S[right] == S[left]) {
                ++right;
            }
            count = right - left;
            res += S[left];
            res += to_string(count);
            left = right;
        }
        return res.size() < len ? res : S;
    }
};