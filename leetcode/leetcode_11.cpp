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

// 双指针
class Solution {
  public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int len = height.size();
        int tmp = 0;
        int left = 0;
        int right = len - 1;
        int h = 0;
        while (left < right) {
            h = min(height[left], height[right]);
            tmp = (right - left) * h;
            res = res > tmp ? res : tmp;
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return res;
    }
};