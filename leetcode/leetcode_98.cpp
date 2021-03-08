/*
验证二叉搜索树
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
    bool isValidBST(TreeNode *root) {
        if (nullptr == root) {
            return right;
        }
        bool res = true;
        if (nullptr != root->left) {
            TreeNode *leftMaxNode = root->left;
            while (nullptr != leftMaxNode->right) {
                leftMaxNode = leftMaxNode->right;
            }
            int leftMaxNum = leftMaxNode->val;
            res = res && root->val > leftMaxNum;
        }
        if (nullptr != root->right) {
            TreeNode *rightMinNode = root->right;
            while (nullptr != rightMinNode->left) {
                rightMinNode = rightMinNode->left;
            }
            int rightMaxNum = rightMinNode->val;
            res = res && root->val < rightMaxNum;
        }
        return res && isValidBST(root->left) && isValidBST(root->right);
    }
};