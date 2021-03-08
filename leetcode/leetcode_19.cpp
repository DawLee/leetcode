#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 简化
class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = new ListNode(0, head);
        ListNode *left = first;
        ListNode *right = head;
        for (int i = 1; i < n; ++i) {
            right = right->next;
        }
        while (nullptr != right->next) {
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        ListNode *res = first->next;
        delete first;
        return res;
    }
};

// 冗余
class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (nullptr == head || n == 0) {
            return head;
        }
        ListNode *left = head;
        ListNode *right = head;
        while (n > 1) {
            right = right->next;
            if (nullptr == right) {
                return head;
            }
            --n;
        }
        while (nullptr != right->next) {
            right = right->next;
            left = left->next;
        }
        if (left == head) {
            ListNode *toDelete = head;
            head = head->next;
            delete toDelete;
        } else if (nullptr == left->next) {
            deleteLastNode(head);
        } else {
            deleteNodeNotLast(left);
        }
        return head;
    }
    void deleteNodeNotLast(ListNode *node) {
        ListNode *toDelete = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete toDelete;
    }
    void deleteLastNode(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return;
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        while (nullptr != curr->next) {
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
    }
};