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
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        int mid = 0;
        int tmp = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            tmp = mid * mid;
            if (tmp == num) {
                return true;
            } else if (tmp < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};