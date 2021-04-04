
/*
圆圈中最后剩下的数字
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

// 约瑟夫环解法
class Solution {
  public:
    int lastRemaining(int n, int m) {
        int last = 0;
        for (int i = 2; i != n + 1; ++i) {
            last = (last + m) % i;
        }
        return last;
    }
};

// list 模拟删除过程，超时
struct List {
    int val;
    List *next;
    List(int num) : val(num), next(nullptr) {}
};

class Solution {
  public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1) {
            return -1;
        }
        List *head = new List(0);
        List *pre = head;
        List *tmp = nullptr;
        for (int i = 1; i < n; ++i) {
            tmp = new List(i);
            pre->next = tmp;
            pre = tmp;
        }
        tmp->next = head;
        tmp = head;
        List *del = nullptr;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                tmp = tmp->next;
            }
            del = tmp->next;
            tmp->val = tmp->next->val;
            tmp->next = tmp->next->next;
            delete del;
            del = nullptr;
        }
        int res = tmp->val;
        delete tmp;
        tmp = nullptr;
        return res;
    }
};