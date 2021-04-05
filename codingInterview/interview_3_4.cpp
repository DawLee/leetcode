// coding Interview 3_4
// 化栈为队
// easy

#include "leetcode.h"
using namespace std;

class MyQueue {
    stack<int> pushStack;
    stack<int> popStack;

  public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { pushStack.emplace(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (pushStack.empty() && popStack.empty()) {
            return -1;
        }
        if (popStack.empty()) {
            pushStackToPopStack();
        }
        int tmp = popStack.top();
        popStack.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        if (pushStack.empty() && popStack.empty()) {
            return -1;
        }
        if (popStack.empty()) {
            pushStackToPopStack();
        }
        return popStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return pushStack.empty() && popStack.empty(); }

    void pushStackToPopStack() {
        while (!pushStack.empty()) {
            popStack.emplace(pushStack.top());
            pushStack.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */