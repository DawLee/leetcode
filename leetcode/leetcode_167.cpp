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
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res(2, 0);
        int len = numbers.size();
        int left = 0;
        int right = len - 1;
        int tmp = 0;
        while (left < right) {
            tmp = numbers[left] + numbers[right];
            if (tmp == target) {
                res[0] = left + 1;
                res[1] = right + 1;
                return res;
            }
            if (tmp < target) {
                ++left;
            } else {
                --right;
            }
        }
        return res;
    }
};