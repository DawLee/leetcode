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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (nullptr == head || m == n) {
            return head;
        }
        ListNode *first = new ListNode(0, head);
        ListNode *left = first;
        ListNode *right = nullptr;
        ListNode *nodeM = nullptr;
        ListNode *tmp = nullptr;
        int index = 0;
        while (index < m - 1) {
            left = left->next;
            ++index;
        }
        nodeM = left->next;
        right = nodeM;
        while (index < n) {
            tmp = right->next;
            right->next = left->next;
            left->next = right;
            right = tmp;
            ++index;
        }
        nodeM->next = right;
        ListNode *res = first->next;
        delete first;
        return res;
    }
};