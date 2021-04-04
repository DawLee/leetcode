
/*
数组中数字出现的次数 II
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
    int singleNumber(vector<int> &nums) {
        int L = 32;
        vector<int> record(L, 0);
        for (const int &n : nums) {
            int2BinaryVec(record, n, L);
        }
        return binary2int(record, L);
    }
    void int2BinaryVec(vector<int> &record, int num, const int &L) {
        int tmp = 0;
        for (int i = 0; i < L; ++i) {
            if (((num >> i) & 1) == 1) {
                tmp = L - i - 1;
                record[tmp] += record[tmp] == 2 ? -2 : 1;
            }
        }
    }
    int binary2int(vector<int> &record, const int &L) {
        int res = 0;
        for (int i = 0; i < L; ++i) {
            res <<= 1;
            res += record[i];
        }
        return res;
    }
};
