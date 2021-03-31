/*
二叉搜索树与双向链表
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
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
  public:
    Node *pre;
    Node *head;
    Node *treeToDoublyList(Node *root) {
        if (nullptr == root) {
            return root;
        }
        inOrder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void inOrder(Node *root) {
        if (nullptr == root) {
            return;
        }
        inOrder(root->left);
        if (nullptr == pre) {
            head = root;
        } else {
            pre->right = root;
        }
        root->left = pre;
        pre = root;
        inOrder(root->right);
    }
};