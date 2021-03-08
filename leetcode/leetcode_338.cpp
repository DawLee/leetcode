/*
比特位计数
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
    vector<int> countBits(int num) {
        vector<int> res = {0};
        if (num == 0) {
            return res;
        }
        while (res.size() <= num) {
            int len = res.size();
            for (int i = 0; i < len; ++i) {
                res.emplace_back(1 + res[i]);
                if (res.size() == num + 1) {
                    return res;
                }
            }
        }
        return res;
    }
};