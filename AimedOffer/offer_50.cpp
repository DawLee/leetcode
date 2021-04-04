/*
丑数
easy
medium *
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
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int a = 0;
        int b = 0;
        int c = 0;
        int n2 = 0;
        int n3 = 0;
        int n5 = 0;
        for (int i = 1; i < n; ++i) {
            n2 = dp[a] * 2;
            n3 = dp[b] * 3;
            n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);
            if (dp[i] == n2) {
                ++a;
            }
            if (dp[i] == n3) {
                ++b;
            }
            if (dp[i] == n5) {
                ++c;
            }
        }
        return dp[n - 1];
    }
};

// 超时
class Solution {
  public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return n;
        }
        const vector<int> zhi = {2, 3, 5};
        unordered_set<int> record;
        record.emplace(1);
        int num = 2;
        int count = 1;
        while (count < n) {
            for (int d : zhi) {
                if (num % d == 0 && record.find(num / d) != record.end()) {
                    record.emplace(num);
                    ++count;
                    break;
                }
            }
            ++num;
        }
        return --num;
    }
};
