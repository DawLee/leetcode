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
    int arrangeCoins(int n) {
        int left = 0;
        int right = n;
        long mid = 0;
        long tmp = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            tmp = mid * (mid + 1) / 2;
            if (tmp == n) {
                return mid;
            } else if (tmp < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};