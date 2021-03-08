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
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n + m + n + 1;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (check(m, n, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool check(int m, int n, int k, int mid) {
        int res = 0;
        int tmp = 0;
        int i = m - 1;
        int j = 0;
        while (i >= 0 && j < n) {
            tmp = i * j + i + j + 1;
            if (mid >= tmp) {
                res += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return res >= k;
    }
};