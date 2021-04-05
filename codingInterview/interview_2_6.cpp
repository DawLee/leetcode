// coding Interview 2_6
// 回文链表
// easy

#include "leetcode.h"
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// reverse + equal
class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        if (nullptr == head) {
            return true;
        }
        ListNode *reList = reverseList(head);
        return isEqualList(head, reList);
    }
    ListNode *reverseList(ListNode *node) {
        ListNode *head = nullptr;
        while (nullptr != node) {
            ListNode *tmp = new ListNode(node->val);
            tmp->next = head;
            head = tmp;
            node = node->next;
        }
        return head;
    }
    bool isEqualList(ListNode *l1, ListNode *l2) {
        while (nullptr != l1 && nullptr != l2) {
            if (l1->val != l2->val) {
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return nullptr == l1 && nullptr == l2;
    }
};

// 栈记录前半段，并与后半段作比较
class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        if (nullptr == head) {
            return true;
        }
        stack<int> record;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *mid = nullptr;
        while (nullptr != fast && nullptr != fast->next) {
            record.emplace(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (nullptr == slow) {
            return true;
        }
        mid = nullptr == fast ? slow : slow->next;
        while (nullptr != mid) {
            if (record.top() != mid->val) {
                return false;
            }
            record.pop();
            mid = mid->next;
        }
        return true;
    }
};