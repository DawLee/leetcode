/*
克隆图
easy
medium *
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

// Definition for a Node.
class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    Node *cloneGraph(Node *node) {
        if (nullptr == node) {
            return nullptr;
        }
        Node *res = new Node(node->val, node->neighbors);
        queue<Node *> record;
        record.emplace(res);
        unordered_map<int, Node *> visit;
        visit.emplace(make_pair(res->val, res));
        while (!record.empty()) {
            int len = record.size();
            for (int k = 0; k < len; ++k) {
                Node *cur = record.front();
                record.pop();
                vector<Node *> vec;
                for (Node *it : cur->neighbors) {
                    if (visit.find(it->val) == visit.end()) {
                        Node *tmp = new Node(it->val, it->neighbors);
                        record.emplace(tmp);
                        vec.emplace_back(tmp);
                        visit.emplace(make_pair(tmp->val, tmp));
                    } else {
                        vec.emplace_back(visit[it->val]);
                    }
                }
                // cur->neighbors = vec; // 可能有错
                cur->neighbors.clear();
                for (Node *n : vec) {
                    cur->neighbors.emplace_back(n);
                }
            }
        }
        return res;
    }
};