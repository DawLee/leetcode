#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (nullptr == head) {
            return head;
        }
        unordered_map<Node *, Node *> record;
        Node *first = new Node(0);
        Node *re = first;
        Node *index = head;
        while (nullptr != index) {
            Node *tmp = new Node(index->val);
            re->next = tmp;
            re = tmp;
            tmp->random = index->random;
            record.emplace(make_pair(index, tmp));
            index = index->next;
        }
        Node *res = first->next;
        delete first;
        index = res;
        while (nullptr != index) {
            if (nullptr != index->random) {
                index->random = record[index->random];
            }
            index = index->next;
        }
        return res;
    }
};