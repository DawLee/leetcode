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
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        int left = 1;
        int right = 1;
        int count = 1;
        for (; right < len; ++right) {
            if (count < 2 && nums[right] == nums[right - 1]) {
                nums[left++] = nums[right];
                ++count;
            } else if (nums[right] != nums[right - 1]) {
                nums[left++] = nums[right];
                count = 1;
            }
        }
        return left;
    }
};