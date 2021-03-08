/*
 二叉搜索树中的插入操作
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

class Solution {
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (nullptr == root) {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

class Solution {
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (nullptr == root) {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        helper(root, val);
        return root;
    }
    void helper(TreeNode *root, int val) {
        if (root->val > val) {
            if (nullptr == root->left) {
                TreeNode *leftNode = new TreeNode(val);
                root->left = leftNode;
                return;
            } else {
                helper(root->left, val);
            }
        } else if (root->val < val) {
            if (nullptr == root->right) {
                TreeNode *rightNode = new TreeNode(val);
                root->right = rightNode;
                return;
            } else {
                helper(root->right, val);
            }
        }
        return;
    }
};