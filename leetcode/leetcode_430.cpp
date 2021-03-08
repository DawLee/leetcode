#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
  public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
  public:
    Node *flatten(Node *head) {
        if (nullptr == head) {
            return head;
        }
        Node *first = new Node;
        first->next = head;
        head->prev = first;
        first->val = 0;
        stack<Node *> record;
        Node *index = first;
        while (nullptr != index->child || nullptr != index->next ||
               !record.empty()) {
            if (nullptr != index->child) {
                if (nullptr != index->next) {
                    record.push(index->next);
                }
                index->next = index->child;
                index->child->prev = index;
                index->child = nullptr;
            } else if (nullptr == index->next) {
                index->next = record.top();
                record.top()->prev = index;
                record.pop();
            }
            index = index->next;
        }
        Node *res = first->next;
        res->prev = nullptr;
        delete first;
        return res;
    }
};