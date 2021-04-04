
/*
二叉搜索树的最近公共祖先
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {}
};

class Solution {
  public:
    TreeNode *res;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return res;
    }
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (nullptr == root) {
            return false;
        }
        bool leftRes = dfs(root->left, p, q);
        bool rightRes = dfs(root->right, p, q);
        if (leftRes && rightRes || root == p || root == q) {
            res = root;
        }
        return leftRes || rightRes || root == p || root == q;
    }
};