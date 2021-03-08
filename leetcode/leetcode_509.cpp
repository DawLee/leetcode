/*
斐波那契数
easy   *
medium
hard
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int f0 = 0;
        int f1 = 1;
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = f0 + f1;
            f0 = f1;
            f1 = res;
        }
        return res;
    }
};