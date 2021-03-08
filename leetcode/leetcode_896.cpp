/*
单调数列
easy   *
medium
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
    bool isMonotonic(vector<int> &A) {
        int len = A.size();
        if (len <= 2) {
            return true;
        }
        return isGreater(A) || isGreater(A, false);
    }
    bool isGreater(vector<int> &A, bool flag = true) {
        int len = A.size();
        for (int i = 1; i < len; ++i) {
            if (flag && A[i] < A[i - 1]) {
                return false;
            } else if (!flag && A[i] > A[i - 1]) {
                return false;
            }
        }
        return true;
    }
};