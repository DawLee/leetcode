/*
分发糖果
easy
medium
hard   *
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
    int candy(vector<int> &ratings) {
        int res = 0;
        int len = ratings.size();
        vector<int> record(len, 1);
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                record[i] = record[i - 1] + 1;
            }
        }
        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                record[i] = max(record[i], record[i + 1] + 1);
            }
        }
        for (int n : record) {
            res += n;
        }
        return res;
    }
};