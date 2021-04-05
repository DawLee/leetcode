// coding Interview 3_1
// 三合一
// easy

#include "leetcode.h"
using namespace std;

class TripleInOne {
    int numberOfStack;
    int oneOfStackSize;
    vector<int> record;
    vector<int> now;

  public:
    TripleInOne(int stackSize) {
        numberOfStack = 3;
        oneOfStackSize = stackSize;
        record.resize(numberOfStack * oneOfStackSize);
        now.resize(numberOfStack, 0);
        for (int i = 0; i < numberOfStack; ++i) {
            now[i] = i * oneOfStackSize;
        }
    }

    void push(int stackNum, int value) {
        if (now[stackNum] == (stackNum + 1) * oneOfStackSize) {
            return;
        }
        record[now[stackNum]] = value;
        ++now[stackNum];
    }

    int pop(int stackNum) {
        if (now[stackNum] == stackNum * oneOfStackSize) {
            return -1;
        }
        int tmp = record[now[stackNum] - 1];
        --now[stackNum];
        return tmp;
    }

    int peek(int stackNum) {
        if (now[stackNum] == stackNum * oneOfStackSize) {
            return -1;
        }
        return record[now[stackNum] - 1];
    }

    bool isEmpty(int stackNum) {
        return now[stackNum] == stackNum * oneOfStackSize;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */