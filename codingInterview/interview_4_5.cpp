// coding Interview 4_5
// 合法二叉搜索树
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
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (nullptr != pre && pre->val >= root->val) {
            return false;
        }
        pre = root;
        return isValidBST(root->right);
    }
};