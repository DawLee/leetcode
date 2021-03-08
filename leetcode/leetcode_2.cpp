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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *first = head;
        int tmp = 0;
        while (nullptr != l1 || nullptr != l2 || tmp != 0) {
            if (nullptr != l1) {
                tmp += l1->val;
                l1 = l1->next;
            }
            if (nullptr != l2) {
                tmp += l2->val;
                l2 = l2->next;
            }
            ListNode *right = new ListNode(tmp % 10);
            first->next = right;
            first = right;
            tmp /= 10;
        }
        ListNode *res = head->next;
        delete head;
        return res;
    }
};