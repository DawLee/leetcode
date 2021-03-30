/*
二叉搜索树迭代器
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class BSTIterator {
  public:
    stack<TreeNode *> record;
    TreeNode *cur = nullptr;
    BSTIterator(TreeNode *root) { cur = root; }

    int next() {
        while (nullptr != cur) {
            record.emplace(cur);
            cur = cur->left;
        }
        cur = record.top();
        record.pop();
        int res = cur->val;
        cur = cur->right;
        return res;
    }

    bool hasNext() { return nullptr != cur || !record.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
