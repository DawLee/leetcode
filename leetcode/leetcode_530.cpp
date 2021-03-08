/*
二叉搜索树的最小绝对差
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int res = INT_MAX;
    TreeNode *pre = nullptr;
    int getMinimumDifference(TreeNode *root) {
        preOrder(root);
        return res;
    }
    void preOrder(TreeNode *root) {
        if (nullptr == root) {
            return;
        }
        preOrder(root->left);
        if (nullptr != pre) {
            res = min(res, root->val - pre->val);
        }
        pre = root;
        preOrder(root->right);
    }
};

class Solution {
  public:
    int getMinimumDifference(TreeNode *root) {
        if (nullptr == root) {
            return INT_MAX;
        }
        int res = INT_MAX;
        if (nullptr != root->left) {
            TreeNode *leftMaxNode = root->left;
            while (nullptr != leftMaxNode->right) {
                leftMaxNode = leftMaxNode->right;
            }
            res = min(res, root->val - leftMaxNode->val);
        }
        if (nullptr != root->right) {
            TreeNode *rightMaxNode = root->right;
            while (nullptr != rightMaxNode->left) {
                rightMaxNode = rightMaxNode->left;
            }
            res = min(res, rightMaxNode->val - root->val);
        }
        return min(res, min(getMinimumDifference(root->left),
                            getMinimumDifference(root->right)));
    }
};