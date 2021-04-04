
/*
重建二叉树
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

class CQueue {
    stack<int> s1;
    stack<int> s2;

  public:
    CQueue() {}

    void appendTail(int value) { s1.emplace(value); }

    int deleteHead() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.emplace(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */