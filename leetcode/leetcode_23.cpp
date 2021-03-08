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

// 一起比较，很慢
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *first = new ListNode(0);
        ListNode *index = first;
        int tmp = 0;
        while (true) {
            tmp = getMinHead(lists);
            if (tmp == -1) {
                break;
            }
            ListNode *node = new ListNode(lists[tmp]->val);
            index->next = node;
            index = node;
            lists[tmp] = lists[tmp]->next;
        }
        ListNode *res = first->next;
        delete first;
        return res;
    }
    int getMinHead(vector<ListNode *> &lists) {
        int len = lists.size();
        int minRes = INT_MAX;
        int res = -1;
        for (int i = 0; i < len; ++i) {
            if (nullptr != lists[i]) {
                res = minRes > lists[i]->val ? i : res;
                minRes = lists[res]->val;
            }
        }
        return res;
    }
};

// 两两合并
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *first = new ListNode(INT_MIN);
        int len = lists.size();
        for (int i = 0; i < len; ++i) {
            first = mergeTwoLists(first, lists[i]);
        }
        ListNode *res = first->next;
        delete first;
        return res;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *first = new ListNode(0, l1);
        ListNode *prel1 = first;
        ListNode *l2tmp = nullptr;
        while (nullptr != l1 && nullptr != l2) {
            if (l1->val <= l2->val) {
                prel1 = l1;
                l1 = l1->next;
            } else {
                l2tmp = l2->next;
                prel1->next = l2;
                prel1 = l2;
                l2->next = l1;
                l2 = l2tmp;
            }
        }
        prel1->next = (nullptr == l1) ? l2 : l1;
        ListNode *res = first->next;
        delete first;
        return res;
    }
};