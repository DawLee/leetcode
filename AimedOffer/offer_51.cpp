
/*
数组中的逆序对
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

// 归并排序
class Solution {
  public:
    int res;
    int reversePairs(vector<int> &nums) {
        res = 0;
        int len = nums.size();
        if (len <= 1) {
            return res;
        }
        vector<int> tmp(len);
        mergeSort(nums, 0, len, tmp);
        return res;
    }
    void mergeSort(vector<int> &nums, int left, int right, vector<int> &tmp) {
        if (left + 1 >= right) {
            return;
        }
        // divide
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, tmp);
        mergeSort(nums, mid, right, tmp);
        // conquer
        int index1 = left;
        int index2 = mid;
        int i = left;
        while (index1 < mid || index2 < right) {
            if (index2 >= right ||
                index1 < mid && nums[index1] <= nums[index2]) {
                tmp[i++] = nums[index1++];
            } else {
                res += mid - index1;
                tmp[i++] = nums[index2++];
            }
        }
        for (int j = left; j < right; ++j) {
            nums[j] = tmp[j];
        }
    }
};