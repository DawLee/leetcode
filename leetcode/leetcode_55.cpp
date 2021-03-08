/*
跳跃游戏
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
    bool canJump(vector<int> &nums) {
        int len = nums.size();
        if (len == 1) {
            return true;
        }
        for (int i = 1; i < len; ++i) {
            if (nums[i - 1] >= i) {
                nums[i] = max(nums[i - 1], i + nums[i]);
            } else {
                nums[i] = nums[i - 1];
            }
            if (nums[i] >= len - 1) {
                return true;
            }
        }
        return false;
    }
};