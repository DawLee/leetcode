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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (nullptr == head || k <= 0) {
            return head;
        }
        ListNode *first = new ListNode(0, head);
        ListNode *tmp = first;
        while (nullptr != tmp) {
            if (isEnoughK(tmp, k)) {
                tmp = reverseKNode(tmp, k);
            } else {
                break;
            }
        }
        ListNode *res = first->next;
        delete first;
        return res;
    }
    bool isEnoughK(ListNode *headtmp, int k) {
        ListNode *tmp = headtmp;
        while (nullptr != headtmp->next) {
            headtmp = headtmp->next;
            --k;
            if (k == 0) {
                return true;
            }
        }
        return false;
    }
    ListNode *reverseKNode(ListNode *headtmp, int k) {
        ListNode *begin = headtmp->next;
        ListNode *right = begin;
        ListNode *tmp = nullptr;
        while (k > 0) {
            tmp = right->next;
            right->next = headtmp->next;
            headtmp->next = right;
            right = tmp;
            --k;
        }
        begin->next = tmp;
        return begin;
    }
};