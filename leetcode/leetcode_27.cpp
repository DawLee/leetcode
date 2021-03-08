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
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size();
        int left = 0;
        int right = len;
        while (left < right) {
            if (nums[left] == val) {
                swap(nums[left], nums[right - 1]);
                --right;
            } else {
                ++left;
            }
        }
        return right;
    }
};