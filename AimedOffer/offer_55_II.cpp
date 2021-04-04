
/*
平衡二叉树
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
    bool isBalanced(TreeNode *root) { return inOrderVisit(root) > -1; }
    int inOrderVisit(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        int leftDepth = inOrderVisit(root->left);
        int rightDepth = inOrderVisit(root->right);
        if (leftDepth == -1 || rightDepth == -1 ||
            abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        return 1 + max(leftDepth, rightDepth);
    }
};