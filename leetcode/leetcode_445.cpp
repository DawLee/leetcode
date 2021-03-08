#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *first = new ListNode(0);
        ListNode *index = first;
        stack<int> s1;
        stack<int> s2;
        stack<int> sres;
        while (nullptr != l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (nullptr != l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int tmp = 0;
        while (!s1.empty() || !s2.empty() || tmp != 0) {
            if (!s1.empty()) {
                tmp += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                tmp += s2.top();
                s2.pop();
            }
            sres.push(tmp % 10);
            tmp /= 10;
        }
        while (!sres.empty()) {
            ListNode *tmp = new ListNode(sres.top());
            sres.pop();
            index->next = tmp;
            index = tmp;
        }
        ListNode *res = first->next;
        delete first;
        return res;
    }
};