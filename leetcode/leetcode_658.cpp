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
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        if (arr.empty()) {
            return arr;
        }
        int len = arr.size();
        int index = binaryFind(arr, x);
        int left = index;
        int right = index;
        while (right - left < k) {
            if (left == 0) {
                ++right;
            } else if (right == len) {
                --left;
            } else if ((x - arr[left - 1]) <= (arr[right] - x)) {
                --left;
            } else {
                ++right;
            }
        }
        vector<int> res(arr.begin() + left, arr.begin() + right);
        return res;
    }
    int binaryFind(vector<int> &arr, int x) {
        int len = arr.size();
        if (x <= arr[0]) {
            return 0;
        } else if (x >= arr[len - 1]) {
            return len - 1;
        }
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if ((x - arr[left - 1]) <= (arr[left] - x)) {
            return left - 1;
        }
        return left;
    }
};