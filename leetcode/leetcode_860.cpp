/*
柠檬水找零
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
    bool lemonadeChange(vector<int> &bills) {
        int five = 0;
        int ten = 0;
        int len = bills.size();
        for (int bill : bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10) {
                --five;
                ++ten;
            } else {
                if (ten > 0) {
                    --ten;
                    --five;
                } else {
                    five -= 3;
                }
            }
            if (five < 0 || ten < 0) {
                return false;
            }
        }
        return true;
    }
};