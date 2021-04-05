// coding Interview 2_7
// 链表相交
// easy

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (nullptr == headA || nullptr == headB) {
            return nullptr;
        }
        int lenA = getListLen(headA);
        int lenB = getListLen(headB);
        int delta = abs(lenA - lenB);
        if (lenA > lenB) {
            headA = fowardListN(headA, delta);
        } else {
            headB = fowardListN(headB, delta);
        }
        while (nullptr != headA || nullptr != headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
    int getListLen(ListNode *head) {
        int count = 0;
        while (nullptr != head) {
            head = head->next;
            ++count;
        }
        return count;
    }
    ListNode *fowardListN(ListNode *head, int n) {
        while (n > 0) {
            head = head->next;
            --n;
        }
        return head;
    }
};