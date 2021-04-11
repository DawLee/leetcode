// coding Interview 5_7
// 配对交换
// easy

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    int exchangeBits(int num) {
        return ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1);
    }
};