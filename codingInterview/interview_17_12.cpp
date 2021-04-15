// coding Interview 17_12
// BiNode
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
    TreeNode *pre = nullptr;
    TreeNode *first = new TreeNode(0);
    TreeNode *convertBiNode(TreeNode *root) {
        inorderTrave(root);
        TreeNode *head = first->right;
        delete first;
        first = nullptr;
        return head;
    }
    void inorderTrave(TreeNode *root) {
        if (nullptr == root) {
            return;
        }
        inorderTrave(root->left);
        if (nullptr == pre) {
            pre = root;
            first->right = pre;
        } else {
            pre->right = root;
            pre = root;
        }
        pre->left = nullptr;
        inorderTrave(root->right);
    }
};