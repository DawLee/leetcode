/*
删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (nullptr == root) {
            return nullptr;
        }
        if (root->val == key) {
            if (nullptr == root->left && nullptr == root->right) {
                delete root;
                root = nullptr;
                return root;
            }
            if (nullptr == root->left) {
                TreeNode *res = root->right;
                delete root;
                return res;
            }
            if (nullptr == root->right) {
                TreeNode *res = root->left;
                delete root;
                return res;
            }
            TreeNode *rightMinNode = root->right;
            while (nullptr != rightMinNode->left) {
                rightMinNode = rightMinNode->left;
            }
            rightMinNode->left = root->left;
            TreeNode *res = root->right;
            delete root;
            return res;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};