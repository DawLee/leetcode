/*
最大数
easy
medium *
hard
*/

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    static bool cmp(int a, int b) {
        string stra = to_string(a);
        string strb = to_string(b);
        return stra + strb > strb + stra;
    }
    string largestNumber(vector<int> &nums) {
        if (nums.empty()) {
            return "";
        }
        string res = "";
        sort(nums.begin(), nums.end(), cmp);
        for (const int &n : nums) {
            res += to_string(n);
        }
        int len = res.size();
        string zeros(len, '0');
        if (res == zeros) {
            return "0";
        }
        return res;
    }
};