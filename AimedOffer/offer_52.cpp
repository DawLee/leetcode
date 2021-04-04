
/*
两个链表的第一个公共节点
easy   *
medium
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 双指针
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
            while (delta > 0) {
                headA = headA->next;
                --delta;
            }
        }
        while (delta > 0) {
            headB = headB->next;
            --delta;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    int getListLen(ListNode *head) {
        int len = 0;
        ListNode *tmp = head;
        while (nullptr != tmp) {
            ++len;
            tmp = tmp->next;
        }
        return len;
    }
};

// 双栈
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (nullptr == headA || nullptr == headB) {
            return nullptr;
        }
        stack<ListNode *> sA;
        stack<ListNode *> sB;
        visitListToStack(headA, sA);
        visitListToStack(headB, sB);
        if (sA.top() != sB.top()) {
            return nullptr;
        }
        ListNode *res = nullptr;
        while (!sA.empty() && !sB.empty() && sA.top() == sB.top()) {
            res = sA.top();
            sA.pop();
            sB.pop();
        }
        return res;
    }
    void visitListToStack(ListNode *head, stack<ListNode *> &record) {
        if (nullptr == head) {
            return;
        }
        ListNode *tmp = head;
        while (nullptr != tmp) {
            record.emplace(tmp);
            tmp = tmp->next;
        }
    }
};