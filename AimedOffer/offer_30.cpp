
/*
包含min函数的栈
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

class MinStack {
    stack<int> s1;
    stack<int> s2;

  public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        s1.emplace(x);
        int count = 0;
        if (!s2.empty() && s2.top() < x) {
            s2.emplace(s2.top());
        } else {
            s2.emplace(x);
        }
    }

    void pop() {
        if (s1.empty()) {
            return;
        }
        s1.pop();
        s2.pop();
    }

    int top() {
        if (s1.empty()) {
            return -1;
        }
        return s1.top();
    }

    int min() {
        if (s2.empty()) {
            return -1;
        }
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */