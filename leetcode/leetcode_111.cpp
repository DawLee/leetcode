/*
二叉树的最小深度
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
    int minDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        int res = helper(root);
        return res;
    }
    int helper(TreeNode *root) {
        if (nullptr == root->left && nullptr == root->right) {
            return 1;
        }
        int leftDepth = INT_MAX;
        int rightDepth = INT_MAX;
        if (nullptr != root->left) {
            leftDepth = helper(root->left);
        }
        if (nullptr != root->right) {
            rightDepth = helper(root->right);
        }
        return 1 + min(leftDepth, rightDepth);
    }
};
class Solution {
  public:
    int minDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        if (nullptr == root->left) {
            return 1 + minDepth(root->right);
        }
        if (nullptr == root->right) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};