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
    int hIndex(vector<int> &citations) {
        if (citations.empty()) {
            return 0;
        }
        int len = citations.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;
        int res = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            res = len - mid;
            if (citations[mid] == 0 || res > citations[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return len - left;
    }
};