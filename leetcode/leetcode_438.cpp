/*
找到字符串中所有字母异位词
easy
medium  *
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

// 双指针，维护一个数组r2，统计双指针内字母的个数，实时更新，并与r1比较
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        int ALPHA = 26;
        vector<int> res;
        int lenp = p.size();
        int lens = s.size();
        if (lenp > lens) {
            return res;
        }
        vector<int> r1(ALPHA, 0);
        for (int i = 0; i < lenp; ++i) {
            ++r1[p[i] - 'a'];
        }
        // 初始化r2=r1
        vector<int> r2(r1);
        int left = 0;
        int right = 0;
        while (right < lens) {
            // 右指针右移时，对应字母个数减一
            // 等于0时表明此时right位置的字母多一个
            while (right < lens && r2[s[right] - 'a'] > 0) {
                --r2[s[right] - 'a'];
                ++right;
            }
            // 如果窗口大小正好是p的长度，此时双指针内是异位词
            // 添加res后，右移左指针，并更新r2
            if (right - left == lenp) {
                res.emplace_back(left);
                ++r2[s[left] - 'a'];
                ++left;
                continue;
            }
            // 当窗口大小不为p长度时，right所指的字母时多余的
            // 因此右移左指针，直到遇到right所指的字母
            while (s[left] != s[right]) {
                ++r2[s[left] - 'a'];
                ++left;
            }
            // 左右指针同时跳过此字母
            // 解释一下，此字母一共有两种情况
            // 1.p不含此字母，那么此时left==right
            // 2.p含有此字母，那么坐右指针同时跳过此字母，不需要更新r2
            ++left;
            ++right;
        }
        return res;
    }
};

// 超时
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int lenp = p.size();
        int len = s.size();
        if (lenp > len) {
            return res;
        }
        unordered_set<char> record;
        sort(p.begin(), p.end());
        for (char c : p) {
            if (record.find(c) == record.end()) {
                record.emplace(c);
            }
        }
        string tmp = s.substr(0, lenp);
        bool pre = isSame(p, tmp);
        if (pre) {
            res.emplace_back(0);
        }
        for (int i = 1; i < len - lenp + 1; ++i) {
            if (record.find(s[i + lenp - 1]) == record.end()) {
                pre = false;
            } else if (pre && s[i - 1] == s[i + lenp - 1]) {
                res.emplace_back(i);
                continue;
            } else {
                tmp = s.substr(i, lenp);
                pre = isSame(p, tmp);
                if (pre) {
                    res.emplace_back(i);
                }
            }
        }
        return res;
    }
    bool isSame(string p, string str) {
        sort(str.begin(), str.end());
        return str == p;
    }
};