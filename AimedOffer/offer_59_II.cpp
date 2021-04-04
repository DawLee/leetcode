
/*
队列的最大值
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

class MaxQueue {
  public:
    queue<int> record;
    deque<int> maxRecord;
    MaxQueue() {}

    int max_value() {
        if (maxRecord.empty()) {
            return -1;
        }
        return maxRecord.front();
    }

    void push_back(int value) {
        record.emplace(value);
        int count = 0;
        while (!maxRecord.empty() && maxRecord.back() < value) {
            maxRecord.pop_back();
            ++count;
        }
        while (count > 0) {
            maxRecord.emplace_back(value);
            --count;
        }
        maxRecord.emplace_back(value);
    }

    int pop_front() {
        if (record.empty()) {
            return -1;
        }
        int res = record.front();
        record.pop();
        maxRecord.pop_front();
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */