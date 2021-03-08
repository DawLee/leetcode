/*
跳跃游戏II
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

// 超时
class Solution {
  public:
    int jump(vector<int> &nums) {
        int len = nums.size();
        vector<int> record(len, -1);
        record[0] = 0;
        for (int i = 0; i < len; ++i) {
            if (record[i] == -1) {
                continue;
            }
            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j >= len) {
                    continue;
                }
                if (record[i + j] == -1) {
                    record[i + j] = record[i] + 1;
                } else {
                    record[i + j] = min(record[i + j], record[i] + 1);
                }
                if (record[len - 1] >= 0) {
                    return record[len - 1];
                }
            }
        }
        return 0;
    }
};