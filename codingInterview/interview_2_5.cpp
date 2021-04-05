// coding Interview 2_5
// 链表求和
// medium

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (nullptr == l1 && nullptr == l2) {
            return nullptr;
        }
        ListNode *first = new ListNode(0);
        ListNode *index = first;
        ListNode *index1 = l1;
        ListNode *index2 = l2;
        int sum = 0;
        int count = 0; // 进位
        while (nullptr != index1 || nullptr != index2 || count != 0) {
            sum = index1 == nullptr ? 0 : index1->val;
            sum += index2 == nullptr ? 0 : index2->val;
            index1 = index1 == nullptr ? nullptr : index1->next;
            index2 = index2 == nullptr ? nullptr : index2->next;
            ListNode *tmp = new ListNode((sum + count) % 10);
            count = (sum + count) / 10;
            index->next = tmp;
            index = tmp;
        }
        ListNode *res = first->next;
        delete first;
        first = nullptr;
        return res;
    }
};