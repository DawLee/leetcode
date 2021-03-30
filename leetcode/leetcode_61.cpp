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
    ListNode *rotateRight(ListNode *head, int k) {
        if (nullptr == head || k == 0) {
            return head;
        }
        pair<int, ListNode *> mess;
        mess = getMessage(head);
        int n = mess.first;
        ListNode *res = nullptr;
        ListNode *tail = mess.second;
        ListNode *newHead = findNode(head, k, n);
        if (tail == newHead) {
            return head;
        }
        res = newHead->next;
        tail->next = head;
        newHead->next = nullptr;
        return res;
    }
    pair<int, ListNode *> getMessage(ListNode *head) {
        pair<int, ListNode *> mess;
        int n = 1;
        ListNode *tail = head;
        mess = make_pair(n, tail);
        if (nullptr == head) {
            return mess;
        }
        while (nullptr != tail->next) {
            tail = tail->next;
            ++n;
        }
        mess = make_pair(n, tail);
        return mess;
    }
    ListNode *findNode(ListNode *head, int k, int n) {
        if (nullptr == head) {
            return head;
        }
        ListNode *first = new ListNode(0, head);
        ListNode *left = first;
        ListNode *right = head;
        k = k % n;
        while (k > 0) {
            right = right->next;
            --k;
        }
        while (nullptr != right->next) {
            right = right->next;
            left = left->next;
        }
        ListNode *res = left->next;
        delete first;
        return res;
    }
};

class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (nullptr == head) {
            return head;
        }
        int len = 0;
        ListNode *tmp = head;
        while (nullptr != tmp) {
            ++len;
            tmp = tmp->next;
        }
        k = len - k % len;
        if (k == 0 || k == len) {
            return head;
        }
        tmp = head;
        ListNode *oldHead = head;
        while (--k > 0) {
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next = nullptr;
        tmp = head;
        while (nullptr != tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = oldHead;
        return head;
    }
};