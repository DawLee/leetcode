
/*
n 个骰子的点数
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

// 动态规划
class Solution {
  public:
    vector<double> dicesProbability(int n) {
        int total = pow(6, n);
        int maxNum = n * 6;
        vector<int> dp(maxNum + 1, 0);
        for (int i = 1; i <= 6; ++i) {
            dp[i] = 1;
        }
        for (int k = 2; k <= n; ++k) {
            for (int i = k * 6; i >= k; --i) {
                dp[i] = 0;
                for (int j = 1; j <= 6; ++j) {
                    if (i - j >= k - 1) {
                        dp[i] += dp[i - j];
                    }
                }
            }
        }
        vector<double> res(maxNum - n + 1, 0);
        for (int i = n; i <= maxNum; ++i) {
            res[i - n] = double(dp[i - n]) / total;
        }
        return res;
    }
};

// 回溯法，超时
class Solution {
  public:
    int minNum;
    int sum;
    vector<int> record;
    vector<double> dicesProbability(int n) {
        sum = 0;
        minNum = n;
        int maxNum = n * 6;
        int len = maxNum - minNum + 1;
        int count = pow(6, n);
        record.resize(len, 0);
        vector<double> res(len, 0);
        backtracking(n);
        for (int i = 0; i < len; ++i) {
            res[i] = double(record[i]) / count;
        }
        return res;
    }
    void backtracking(int n) {
        if (n <= 0) {
            ++record[sum - minNum];
            return;
        }
        --n;
        for (int i = 1; i <= 6; ++i) {
            sum += i;
            backtracking(n);
            sum -= i;
        }
    }
};