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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (nullptr == head) {
            return head;
        }
        ListNode *first = new ListNode(0, head);
        ListNode *left = first;
        ListNode *right = left->next;
        while (nullptr != right) {
            if (nullptr != right->next && right->val == right->next->val) {
                while (nullptr != right->next &&
                       right->val == right->next->val) {
                    right = right->next;
                }
                left->next = right->next;
            } else {
                left = right;
            }
            right = right->next;
        }
        head = first->next;
        delete first;
        return head;
    }
};