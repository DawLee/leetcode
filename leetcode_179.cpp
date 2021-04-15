#include "leetcode.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *swapListNode(ListNode *input, int index1, int index2) {
    if (nullptr == input) {
        return input;
    }
    if (index1 < 1 || index2 < 1) {
        return nullptr;
    }
    ListNode *first = new ListNode(0);
    first->next = input;
    ListNode *pre1 = findPreNode(first, index1);
    ListNode *pre2 = findPreNode(first, index2);
    if (nullptr == pre1 || nullptr == pre2) {
        return nullptr;
    }
    if (index1 + 1 == index2) {
        swapNextNode(pre1);
    } else if (index2 + 1 == index1) {
        swapNextNode(pre2);
    } else if (index1 != index2) {
        ListNode *cur1 = pre1->next;
        ListNode *cur2 = pre2->next;
        pre1->next = cur1->next;
        pre2->next = cur2->next;
        cur1->next = pre2->next;
        cur2->next = pre1->next;
        pre1->next = cur2;
        pre2->next = cur1;
    }
    // index1 == index2
    ListNode *head = first->next;
    delete first;
    first = nullptr;
    return head;
}

void swapNextNode(ListNode *pre) {
    ListNode *cur1 = pre->next;
    ListNode *cur2 = cur1->next;
    pre->next = cur2;
    cur1->next = cur2->next;
    cur2->next = cur1;
}

ListNode *findPreNode(ListNode *root, int index) {
    ListNode *pre = root;
    int i = 1;
    while (nullptr != pre->next && i < index) {
        pre = pre->next;
        ++i;
    }
    if (i == index) {
        return pre;
    } else {
        return nullptr;
    }
}
