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

// 迭代
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (nullptr == head) {
            return head;
        }
        ListNode *left = head;
        ListNode *right = head;
        ListNode *tmp = nullptr;
        while (nullptr != right) {
            tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
        }
        head->next = nullptr;
        return left;
    }
};

// 递归
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (nullptr == head) {
            return head;
        }
        ListNode *res = reverseListRec(head, head);
        return res;
    }
    ListNode *reverseListRec(ListNode *head, ListNode *index) {
        if (nullptr == index) {
            return head;
        }
        ListNode *tmp = index->next;
        index->next = head;
        head = index;
        index = tmp;
        return reverseListRec(head, index);
    }
};