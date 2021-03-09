/*
加油站
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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size();
        int tmp = 0;
        int maxIndex = 0;
        int maxNum = INT_MIN;
        for (int i = 0; i < len; ++i) {
            tmp += cost[i] - gas[i];
            if (tmp > maxNum) {
                maxIndex = i;
                maxNum = tmp;
            }
        }
        if (tmp > 0) {
            return -1;
        }
        return (maxIndex + 1) % len;
    }
};