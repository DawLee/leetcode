// coding Interview 2_4
// 分割链表
// medium

#include "leetcode.h"
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        if (nullptr == head) {
            return head;
        }
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode *l = left;
        ListNode *r = right;
        ListNode *tmp = head;
        while (nullptr != tmp) {
            if (tmp->val < x) {
                l->next = tmp;
                l = l->next;
            } else {
                r->next = tmp;
                r = r->next;
            }
            tmp = tmp->next;
        }
        r->next = nullptr;
        l->next = right->next;
        head = left->next;
        delete left;
        delete right;
        left = nullptr;
        right = nullptr;
        return head;
    }
};