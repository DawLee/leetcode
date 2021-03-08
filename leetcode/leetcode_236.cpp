/*
二叉树的最近公共祖先
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

// 后序遍历, 自底向上
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (nullptr == root || root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode *leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightNode = lowestCommonAncestor(root->right, p, q);

        if (nullptr != leftNode && nullptr != rightNode) {
            return root;
        } else if (nullptr == leftNode && nullptr != rightNode) {
            return rightNode;
        } else if (nullptr == rightNode && nullptr != leftNode) {
            return leftNode;
        }
        return nullptr;
    }
};

// 前序遍历，时间太久
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return helper(root, p, q);
    }
    TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode *pNode = isHaverNode(root->left, p) ? root->left : root->right;
        TreeNode *qNode = isHaverNode(root->left, q) ? root->left : root->right;
        if (pNode != qNode) {
            return root;
        } else {
            return helper(pNode, p, q);
        }
    }
    bool isHaverNode(TreeNode *root, TreeNode *target) {
        if (nullptr == root) {
            return false;
        }
        if (root->val == target->val) {
            return true;
        }
        return isHaverNode(root->left, target) ||
               isHaverNode(root->right, target);
    }
};