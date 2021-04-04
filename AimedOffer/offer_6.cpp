
/*
从尾到头打印链表
easy   *
medium
hard
*/

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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    vector<int> res;
    vector<int> reversePrint(ListNode *head) {
        visitList(head);
        return res;
    }
    void visitList(ListNode *Node) {
        if (nullptr == Node) {
            return;
        }
        if (nullptr != Node->next) {
            visitList(Node->next);
        }
        res.emplace_back(Node->val);
    }
};