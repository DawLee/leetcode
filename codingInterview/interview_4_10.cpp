// coding Interview 4_10
// 检查子树
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

// 数据较少时推荐
class Solution {
  public:
    bool checkSubTree(TreeNode *t1, TreeNode *t2) {
        string strT1 = "";
        string strT2 = "";
        getTreeString(t1, strT1);
        getTreeString(t2, strT2);
        return strT1.find(strT2) == strT1.npos ? false : true;
    }
    void getTreeString(TreeNode *root, string &str) {
        if (nullptr == root) {
            str += "n,";
            return;
        }
        str += to_string(root->val) + ',';
        getTreeString(root->left, str);
        getTreeString(root->right, str);
    }
};

// 大数据时采用此方式
class Solution {
  public:
    bool checkSubTree(TreeNode *t1, TreeNode *t2) {
        if (nullptr == t2) {
            return true;
        }
        return isSubTree(t1, t2);
    }
    bool isSubTree(TreeNode *t1, TreeNode *t2) {
        if (nullptr == t1) {
            return false;
        }
        if (t1->val == t2->val && isSameTree(t1, t2)) {
            return true;
        }
        return isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
    }
    bool isSameTree(TreeNode *t1, TreeNode *t2) {
        if (nullptr == t2) {
            return true;
        }
        if (nullptr == t1) {
            return false;
        }
        if (t2->val != t1->val) {
            return false;
        }
        return isSameTree(t1->left, t2->left) &&
               isSameTree(t1->right, t2->right);
    }
};