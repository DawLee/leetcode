/*
验证二叉树的前序序列化
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

// stack
class Solution {
  public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) {
            return false;
        }
        int len = preorder.size();
        stack<int> record;
        record.emplace(1);
        int i = 0;
        while (i < len) {
            if (record.empty()) {
                return false;
            }
            if (preorder[i] == ',') {
                ++i;
            } else if (preorder[i] == '#') {
                --record.top();
                if (record.top() == 0) {
                    record.pop();
                }
                ++i;
            } else {
                while (i < len && preorder[i] != ',') {
                    ++i;
                }
                --record.top();
                if (record.top() == 0) {
                    record.pop();
                }
                record.emplace(2);
            }
        }
        if (record.empty()) {
            return true;
        }
        return false;
    }
};

class Solution {
  public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) {
            return false;
        }
        int len = preorder.size();
        int count = 1;
        int i = 0;
        while (i < len) {
            if (count == 0) {
                return false;
            }
            if (preorder[i] == ',') {
                ++i;
            } else if (preorder[i] == '#') {
                --count;
                ++i;
            } else {
                while (i < len && preorder[i] != ',') {
                    ++i;
                }
                ++count;
            }
        }
        if (count == 0) {
            return true;
        }
        return false;
    }
};