// coding Interview 3_3
// 堆盘子
// medium

#include "leetcode.h"
using namespace std;

class StackOfPlates {
    vector<stack<int>> record;
    int StackOfCap;

  public:
    StackOfPlates(int cap) { StackOfCap = cap; }

    void push(int val) {
        if (StackOfCap == 0) {
            return;
        }
        if (record.empty() || record.back().size() == StackOfCap) {
            stack<int> tmp;
            record.emplace_back(tmp);
        }
        record.back().emplace(val);
    }

    int pop() {
        if (StackOfCap == 0 || record.empty()) {
            return -1;
        }
        int tmp = record.back().top();
        record.back().pop();
        if (record.back().empty()) {
            record.pop_back();
        }
        return tmp;
    }

    int popAt(int index) {
        if (StackOfCap == 0 || index >= record.size() ||
            record[index].empty()) {
            return -1;
        }
        int tmp = record[index].top();
        record[index].pop();
        if (record[index].empty()) {
            record.erase(record.begin() + index);
        }
        return tmp;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */