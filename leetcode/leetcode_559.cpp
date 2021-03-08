/*
N叉树的最大深度
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

// Definition for a Node.
class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    int maxDepth(Node *root) {
        int res = helper(root);
        return res;
    }
    int helper(Node *root) {
        if (nullptr == root) {
            return 0;
        }
        int res = 0;
        int len = root->children.size();
        for (int i = 0; i < len; ++i) {
            res = max(res, helper(root->children[i]));
        }
        return res + 1;
    }
};