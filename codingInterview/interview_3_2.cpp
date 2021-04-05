// coding Interview 3_2
// 栈的最小值
// easy

#include "leetcode.h"
using namespace std;

class MinStack {
    stack<int> record;
    stack<int> minRecord;

  public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        record.emplace(x);
        if (!minRecord.empty() && minRecord.top() < x) {
            minRecord.emplace(minRecord.top());
        } else {
            minRecord.emplace(x);
        }
    }

    void pop() {
        record.pop();
        minRecord.pop();
    }

    int top() { return record.top(); }

    int getMin() { return minRecord.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */