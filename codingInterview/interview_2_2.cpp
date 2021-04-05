// coding Interview 2_2
// 返回倒数第 k 个节点
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
    int kthToLast(ListNode *head, int k) {
        if (nullptr == head) {
            return -1;
        }
        ListNode *left = head;
        ListNode *right = head;
        while (k > 0) {
            right = right->next;
            --k;
        }
        while (nullptr != right) {
            left = left->next;
            right = right->next;
        }
        return left->val;
    }
};