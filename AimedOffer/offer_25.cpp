/*
合并两个排序的链表
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

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *first = new ListNode(0);
        ListNode *cur = first;
        while (nullptr != l1 || nullptr != l2) {
            if (nullptr == l1) {
                cur->next = l2;
                break;
            } else if (nullptr == l2) {
                cur->next = l1;
                break;
            } else if (l1->val <= l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        ListNode *head = first->next;
        delete first;
        return head;
    }
};