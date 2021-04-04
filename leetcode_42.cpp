/*
接雨水
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
    int trap(vector<int> &height) {
        if (height.empty()) {
            return 0;
        }
        int res = 0;
        int len = height.size();
        int d = 0;
        int h = 0;
        int width = 0;
        stack<int> record;
        for (int i = 0; i < len; ++i) {
            while (!record.empty() && height[record.top()] < height[i]) {
                d = record.top();
                record.pop();
                if (record.empty()) {
                    break;
                }
                h = min(height[record.top()], height[i]) - height[d];
                int width = i - record.top() - 1;
                res += h * width;
            }
            record.emplace(i);
        }
        return res;
    }
};

class Solution {
  public:
    int trap(vector<int> &height) {
        if (height.empty()) {
            return 0;
        }
        int res = 0;
        int len = height.size();
        int left = 0;
        int right = len - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                res += leftMax - height[left];
                ++left;
            } else {
                res += rightMax - height[right];
                --right;
            }
        }
        return res;
    }
};