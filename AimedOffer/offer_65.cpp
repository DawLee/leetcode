
/*
不用加减乘除做加法
easy
medium *
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
    int add(int a, int b) {
        do {
            int c = (unsigned int)(a & b) << 1;
            a ^= b;
            b = c;
        } while (b != 0);
        return a;
    }
};
