// coding Interview 5_4
// 下一个数
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    int MAX_LEN;
    vector<int> findClosedNumbers(int num) {
        MAX_LEN = 32;
        vector<int> res(2, 0);
        if ((num & (num - 1)) == 0) {
            res[0] = num << 1;
            res[1] = num >> 1;
            return res;
        }
        int smallNum1 = changeFirstNum(num, 0); // 第一个0置1
        int smallNum2 = num & (num - 1);        // 第一个1置0
        int bigNum1 = changeFirstNum(num, 1);   //
        int bigNum = bigNum1 & (bigNum1 - 1);
        res[0] = bigNum;
        res[1] = (smallNum1 & smallNum2);
        return res;
    }
    int changeFirstNum(const int num, int n) {
        int res = -1;
        bool flag = false;
        for (int i = 0; i < MAX_LEN; ++i) {
            if (1 == ((num >> i) & 1)) {
                --n;
                if (n == 0) {
                    res = num ^ (1 << i);
                    break;
                }
            }
        }
        return res;
    }
};