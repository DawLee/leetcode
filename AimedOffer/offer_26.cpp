/*
树的子结构
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (nullptr == A || nullptr == B) {
            return false;
        }
        return preOrder(A, B);
    }
    bool preOrder(TreeNode *root, TreeNode *B) {
        if (nullptr == root) {
            return false;
        }
        if (root->val = B->val && isSubTree(root, B)) {
            return true;
        }
        return preOrder(root->left, B) || preOrder(root->right, B);
    }
    bool isSubTree(TreeNode *curA, TreeNode *curB) {
        if (nullptr == curB) {
            return true;
        } else if (nullptr == curA) {
            return false;
        }
        if (curA->val != curB->val) {
            return false;
        }
        return isSubTree(curA->left, curB->left) &&
               isSubTree(curA->right, curB->right);
    }
};