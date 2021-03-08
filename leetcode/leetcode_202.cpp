#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
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
    bool isHappy(int n) {
        unordered_set<int> record;
        int tmp = n;
        while (true) {
            if (record.find(tmp) == record.end()) {
                record.insert(tmp);
            } else {
                return false;
            }
            tmp = changeNum(tmp);
            if (tmp == 1) {
                return true;
            }
        }
    }
    int changeNum(int n) {
        int res = 0;
        int tmp = 0;
        while (n > 0) {
            tmp = n % 10;
            res += tmp * tmp;
            n /= 10;
        }
        return res;
    }
};