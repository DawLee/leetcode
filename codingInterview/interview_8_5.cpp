// coding Interview 8_5
// 递归乘法
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    int multiply(int A, int B) {
        int bigger = max(A, B);
        int smaller = min(A, B);
        if (smaller == 0) {
            return 0;
        }
        int res = multiplyHelper(bigger, smaller);
        return res;
    }
    int multiplyHelper(const int bigger, int smaller) {
        if (smaller == 1) {
            return bigger;
        }
        int res = 0;
        int mid = smaller >> 1;
        int helfProd = multiplyHelper(bigger, mid);
        res += helfProd + helfProd;
        if ((smaller & 1) == 1) {
            res += bigger;
        }
        return res;
    }
};