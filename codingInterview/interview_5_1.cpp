// coding Interview 5_1
// 插入
// easy

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    int insertBits(int N, int M, int i, int j) {
        for (int k = i; k <= j; ++k) {
            N &= ~(1 << k);
        }
        return N | (M << i);
    }
};