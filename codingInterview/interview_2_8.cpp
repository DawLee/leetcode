// coding Interview 2_8
// 环路检测
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
    ListNode *detectCycle(ListNode *head) {
        if (nullptr == head) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (nullptr != fast && nullptr != fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (nullptr == fast || nullptr == fast->next) {
            return nullptr;
        }
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};