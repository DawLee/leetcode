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
        ListNode *pre = head;
        ListNode *cur = head;
        while (nullptr != cur) {
            while (nullptr != cur && cur->val == pre->val) {
                cur = cur->next;
            }
            pre->next = cur;
            pre = cur;
        }
        return head;
    }
};