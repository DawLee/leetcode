/*
有效三角形的个数
easy
medium  *
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
    int triangleNumber(vector<int> &nums) {
        int len = nums.size();
        if (len < 3) {
            return 0;
        }
        int res = 0;
        int j = 0;
        int k = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 1; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            j = i + 1;
            k = j + 1;
            while (k < len && j < len - 1) {
                if (nums[k] == 0) {
                    ++k;
                }
                if (nums[j] == 0) {
                    ++j;
                }
                while (j >= k) {
                    ++k;
                }
                if (nums[i] + nums[j] > nums[k]) {
                    res += k - j;
                    ++k;
                } else {
                    ++j;
                }
            }
        }
        return res;
    }
};