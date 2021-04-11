// coding Interview 4_6
// 后继者
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
    TreeNode *res = nullptr;
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        // p 有右节点时
        if (nullptr != p && nullptr != p->right) {
            res = p->right;
            while (nullptr != res->left) {
                res = res->left;
            }
            return res;
        }
        // p 没有右节点时
        findPre(root, p);
        return res;
    }
    void findPre(TreeNode *root, TreeNode *p) {
        if (nullptr == root || nullptr != res) {
            return;
        }
        findPre(root->right, p);
        if (root == p) {
            res = pre;
        }
        pre = root;
        findPre(root->left, p);
    }
};