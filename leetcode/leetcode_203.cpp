#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 哨兵节点
class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *first = new ListNode(0, head);
        ListNode *prev = first;
        ListNode *curr = head;
        ListNode *toDelete = nullptr;
        while (nullptr != curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                toDelete = curr;
            } else {
                prev = curr;
            }
            curr = curr->next;
            if (nullptr != toDelete) {
                delete toDelete;
                toDelete = nullptr;
            }
        }
        ListNode *res = first->next;
        delete first;
        return res;
    }
};

// 首先单独处理头节点
class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        if (nullptr == head) {
            return head;
        }
        // 处理头节点
        while (nullptr != head && head->val == val) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        ListNode *res = head;
        while (nullptr != head && nullptr != head->next) {
            if (head->next->val == val) {
                ListNode *tmp = head->next;
                head->next = head->next->next;
                delete tmp;
            } else {
                head = head->next;
            }
        }
        return res;
    }
};
