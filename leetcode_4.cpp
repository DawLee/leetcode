/*
寻找两个正序数组的中位数
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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len = nums1.size() + nums2.size();
        if (len % 2 == 1) {
            return getKthElement(nums1, nums2, len / 2 + 1);
        } else {
            return (getKthElement(nums1, nums2, len / 2) +
                    getKthElement(nums1, nums2, len / 2 + 1)) /
                   2.0;
        }
    }
    int getKthElement(const vector<int> &nums1, const vector<int> &nums2,
                      int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int left1 = 0;
        int left2 = 0;
        int mid1 = 0;
        int mid2 = 0;
        while (true) {
            if (left1 == len1) {
                return nums2[left2 + k - 1];
            }
            if (left2 == len2) {
                return nums1[left1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[left1], nums2[left2]);
            }
            mid1 = min(left1 + k / 2 - 1, len1 - 1);
            mid2 = min(left2 + k / 2 - 1, len2 - 1);
            if (nums1[mid1] <= nums2[mid2]) {
                k -= mid1 - left1 + 1;
                left1 = mid1 + 1;
            } else {
                k -= mid2 - left2 + 1;
                left2 = mid2 + 1;
            }
        }
    }
};