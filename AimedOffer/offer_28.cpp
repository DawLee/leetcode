/*
对称的二叉树
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }
        return isSymtTree(root->left, root->right);
    }
    bool isSymtTree(TreeNode *A, TreeNode *B) {
        if (nullptr == A && nullptr == B) {
            return true;
        } else if (nullptr == A || nullptr == B) {
            return false;
        }
        if (A->val != B->val) {
            return false;
        }
        return isSymtTree(A->left, B->right) && isSymtTree(A->right, B->left);
    }
};