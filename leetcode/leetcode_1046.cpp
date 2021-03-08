/*
最后一块石头的重量
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
    int lastStoneWeight(vector<int> &stones) {
        int tmp1 = 0;
        int tmp2 = 0;
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            tmp1 = stones.back();
            stones.pop_back();
            tmp2 = stones.back();
            stones.pop_back();
            if (tmp1 != tmp2) {
                stones.emplace_back(tmp1 - tmp2);
            }
        }
        int res = stones.size() == 0 ? 0 : stones[0];
        return res;
    }
};