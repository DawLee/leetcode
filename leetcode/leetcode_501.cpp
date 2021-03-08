/*
二叉搜索树中的众数
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

class Solution {
  public:
    int maxLen = 0;
    int tmp = 0;
    vector<int> res;
    TreeNode *pre = nullptr;
    vector<int> findMode(TreeNode *root) {
        inOrder(root);
        return res;
    }
    void inOrder(TreeNode *root) {
        if (nullptr == root) {
            return;
        }
        inOrder(root->left);
        if (nullptr == pre) {
            tmp = 1;
        } else if (pre->val == root->val) {
            ++tmp;
        } else {
            tmp = 1;
        }
        if (tmp == maxLen) {
            res.emplace_back(root->val);
        } else if (tmp > maxLen) {
            maxLen = tmp;
            res.clear();
            res.emplace_back(root->val);
        }
        pre = root;
        inOrder(root->right);
    }
};