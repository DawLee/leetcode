
/*
构建乘积数组
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
    vector<int> constructArr(vector<int> &a) {
        int len = a.size();
        vector<int> b(len, 1);
        for (int i = 1; i < len; ++i) {
            b[i] = b[i - 1] * a[i - 1];
        }
        int tmp = 1;
        for (int i = len - 2; i >= 0; --i) {
            tmp *= a[i + 1];
            b[i] *= tmp;
        }
        return b;
    }
};