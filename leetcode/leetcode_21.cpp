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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *index = head;
        while (nullptr != l1 && nullptr != l2) {
            ListNode *tmp = new ListNode(l1->val);
            if (l1->val <= l2->val) {
                tmp->val = l1->val;
                l1 = l1->next;
            } else {
                tmp->val = l2->val;
                l2 = l2->next;
            }
            index->next = tmp;
            index = tmp;
        }
        if (nullptr == l1) {
            index->next = l2;
        } else {
            index->next = l1;
        }
        ListNode *res = head->next;
        delete head;
        return res;
    }
};