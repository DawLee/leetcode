// coding Interview 2_1
// 移除重复节点
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
    ListNode *removeDuplicateNodes(ListNode *head) {
        if (nullptr == head) {
            return head;
        }
        ListNode *left = head;
        ListNode *right = nullptr;
        while (nullptr != left) {
            right = left;
            while (nullptr != right && nullptr != right->next) {
                if (right->next->val == left->val) {
                    right->next = right->next->next;
                } else {
                    right = right->next;
                }
            }
            left = left->next;
        }
        return head;
    }
};