// coding Interview 4_8
// 首个共同祖先
// medium

#include "leetcode.h"
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
        if ((leftRes && rightRes) ||
            ((root == p || root == q) && (leftRes || rightRes))) {
            res = root;
            return true;
        }
        return leftRes || rightRes || root == p || root == q;
    }
};