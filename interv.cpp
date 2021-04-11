// coding Interview 5_8
// 绘制直线
// medium

#include "leetcode.h"
using namespace std;

struct Interval {
    int start;
    int end;
    Interval(int start, int end) : start(start), end(end){};
};

int main() {
    Interval cur = new Interval();
    Interval tmp(0, 0);
    tmp.start = 0;
    tmp.end = 0;
}