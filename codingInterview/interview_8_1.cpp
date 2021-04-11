// coding Interview 8_1
// 三步问题
// easy

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    int waysToStep(int n) {
        if (n < 3) {
            return n;
        }
        int INT = 1e9 + 7;
        int a = 1;
        int b = 1;
        int c = 2;
        int d = 0;
        int i = 3;
        while (i++ <= n) {
            d = ((a + b) % INT + c) % INT;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};