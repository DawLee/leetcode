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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    void deleteNode(ListNode *node) {
        if (nullptr == node) {
            return;
        }
        ListNode *toDelete = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete toDelete;
    }
};