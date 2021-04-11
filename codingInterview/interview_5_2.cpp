// coding Interview 5_2
// 二进制数转字符串
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    string printBin(double num) {
        if (num == 0.0 || num == 1.0) {
            return to_string(num);
        }
        const int MAX_LEN = 32;
        string res = "0.";
        double count = 1;
        while (res.size() <= MAX_LEN && num > 0) {
            count /= 2;
            if (num >= count) {
                res += '1';
                num -= count;
            } else {
                res += '0';
            }
        }
        return res.size() > MAX_LEN ? "ERROR" : res;
    }
};