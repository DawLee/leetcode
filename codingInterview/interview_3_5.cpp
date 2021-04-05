// coding Interview 3_5
// 栈排序
// easy

#include "leetcode.h"
using namespace std;

class SortedStack {
    stack<int> record;
    stack<int> tmpStack;

  public:
    SortedStack() {}

    void push(int val) {
        while (!record.empty() && record.top() < val) {
            tmpStack.emplace(record.top());
            record.pop();
        }
        record.emplace(val);
        while (!tmpStack.empty()) {
            record.emplace(tmpStack.top());
            tmpStack.pop();
        }
    }

    void pop() {
        if (record.empty()) {
            return;
        }
        record.pop();
    }

    int peek() { return record.empty() ? -1 : record.top(); }

    bool isEmpty() { return record.empty(); }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */