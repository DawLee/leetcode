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

// 搜索偶数
class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            mid -= (mid % 2 == 0) ? 0 : 1; // mid确保为偶数
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

// 全部搜索
class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid == len - 1 || mid == 0) {
                return nums[mid];
            } else if (mid % 2 == 0 && nums[mid] != nums[mid - 1] ||
                       mid % 2 != 0 && nums[mid] != nums[mid + 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << left + 1 << endl;
        return nums[left + 1];
    }
};