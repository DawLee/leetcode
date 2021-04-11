// coding Interview 5_3
// 反转数位
// easy

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    int reverseBits(int num) {
        const int MAX_LEN = 32;
        int res = 0;
        vector<int> record(2, 0);
        for (int i = 0; i < MAX_LEN; ++i) {
            if (1 == ((num >> i) & 1)) {
                ++record[0];
                ++record[1];
            } else {
                res = max(res, record[0]);
                record[0] = record[1] + 1;
                record[1] = 0;
            }
        }
        res = max(res, record[0]);
        return res;
    }
};