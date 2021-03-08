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
    ListNode *swapPairs(ListNode *head) {
        if (nullptr == head) {
            return head;
        }
        ListNode *First = new ListNode(0, head);
        ListNode *last = First;
        ListNode *first = head;
        ListNode *second = nullptr;
        while (nullptr != first && nullptr != first->next) {
            second = first->next;
            first->next = second->next;
            second->next = first;
            last->next = second;
            last = first;
            first = first->next;
        }
        ListNode *res = First->next;
        delete First;
        return res;
    }
};