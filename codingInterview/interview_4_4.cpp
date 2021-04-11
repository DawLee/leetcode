// coding Interview 4_4
// 检查平衡性
// easy

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
    bool isBalanced(TreeNode *root) { return treeHight(root) > -1; }
    int treeHight(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        int leftHight = treeHight(root->left);
        int rightHight = treeHight(root->right);
        if (leftHight == -1 || rightHight == -1 ||
            abs(leftHight - rightHight) > 1) {
            return -1;
        }
        return 1 + max(leftHight, rightHight);
    }
};