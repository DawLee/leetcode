/*
最少交换次数来组合所有的 1
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
    int minSwaps(vector<int> &data) {
        int len = data.size();
        int ones = 0;
        for (int &i : data) {
            ones += i == 1 ? 1 : 0;
        }
        int left = 0;
        int right = 0;
        int zero = 0;
        while (right < ones) {
            zero += data[right++] == 0 ? 1 : 0;
        }
        int res = zero;
        while (right < len) {
            zero += data[right++] == 0 ? 1 : 0;
            zero -= data[left++] == 0 ? 1 : 0;
            res = min(res, zero);
        }
        return res;
    }
};