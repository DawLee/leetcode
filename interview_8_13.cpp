// coding Interview 8_13
// 堆箱子
// hard

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    static bool cmp(vector<int> &vec1, vector<int> &vec2) {
        return vec1[0] < vec2[0];
    }
    int pileBox(vector<vector<int>> &box) {
        if (box.empty()) {
            return 0;
        }
        sort(box.begin(), box.end(), cmp);
        int len = box.size();
        vector<int> dp(len, 0);
        dp[0] = box[0][2];
        int res = dp[0];
        for (int i = 1; i < len; ++i) {
            int maxh = 0;
            for (int j = 0; j < i; ++j) {
                if (box[j][0] < box[i][0] && box[j][1] < box[i][1] &&
                    box[j][2] < box[i][2]) {
                    maxh = max(maxh, dp[j]);
                }
            }
            dp[i] = maxh + box[i][2];
            res = max(dp[i], res);
        }
        return res;
    }
};