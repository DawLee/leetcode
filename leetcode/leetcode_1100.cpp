/*
长度为 K 的无重复字符子串
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

class Solution {
  public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int res = 0;
        int len = S.size();
        if (len < K || K > 26) {
            return 0;
        }
        vector<int> record(26, 0);
        for (int i = 0; i < K; ++i) {
            ++record[S[i] - 'a'];
        }
        int left = 0;
        int right = K - 1;
        while (right < len) {
            if (myCheck(record)) {
                ++res;
            }
            ++right;
            if (right < len) {
                ++record[S[right] - 'a'];
            }
            --record[S[left] - 'a'];
            ++left;
        }
        return res;
    }
    bool myCheck(vector<int> &record) {
        for (const int &i : record) {
            if (i > 1) {
                return false;
            }
        }
        return true;
    }
};