#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    bool judgeSquareSum(int c) {
        long i = 0;
        long j = int(sqrt(c)) + 1;
        int tmp = 0;
        while (i <= j) {
            tmp = i * i + j * j;
            if (tmp == c) {
                return true;
            }
            if (tmp < c) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};