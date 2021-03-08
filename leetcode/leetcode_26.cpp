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
        int left = 0;
        int right = 0;
        for (; right < len; ++right) {
            if (nums[right] == nums[left]) {
                continue;
            }
            // swap(nums[left + 1], nums[right]);
            nums[left + 1] = nums[right];
            ++left;
        }
        return left + 1;
    }
};

// 早期
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() < 2)
            return nums.size();
        int index = 1;
        int temp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[index - 1]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};