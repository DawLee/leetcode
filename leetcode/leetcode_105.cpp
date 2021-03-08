/*
从前序与中序遍历序列构造二叉树
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

// Definition for a Node.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        int len = preorder.size();
        pair<int, int> start(0, len - 1);
        TreeNode *root = new TreeNode(preorder[0]);
        buildTreeHelper(preorder, inorder, start, start, root);
        return root;
    }
    void buildTreeHelper(vector<int> &preorder, vector<int> &inorder,
                         pair<int, int> preOrder, pair<int, int> inOrder,
                         TreeNode *root) {
        if (preOrder.first >= preOrder.second) {
            return;
        }
        pair<int, int> inOrderLeft(
            inOrder.first, getInorderLeftRight(inorder, inOrder.first,
                                               preorder[preOrder.first]) -
                               1);
        pair<int, int> inOrderRight(inOrderLeft.second + 2, inOrder.second);
        int lenLeft = inOrderLeft.second - inOrderLeft.first + 1;
        int lenRight = inOrderRight.second - inOrderRight.first + 1;
        pair<int, int> preOrderLeft(preOrder.first + 1,
                                    preOrder.first + lenLeft);
        pair<int, int> preOrderRight(preOrderLeft.second + 1, preOrder.second);
        if (lenLeft > 0) {
            TreeNode *leftNode = new TreeNode(preorder[preOrderLeft.first]);
            root->left = leftNode;
            buildTreeHelper(preorder, inorder, preOrderLeft, inOrderLeft,
                            leftNode);
        }
        if (lenRight > 0) {
            TreeNode *rightNode = new TreeNode(preorder[preOrderRight.first]);
            root->right = rightNode;
            buildTreeHelper(preorder, inorder, preOrderRight, inOrderRight,
                            rightNode);
        }
    }
    int getInorderLeftRight(vector<int> &inorder, int start, int target) {
        int i = start;
        while (true) {
            if (inorder[i] == target) {
                return i;
            }
            ++i;
        }
        return i;
    }
};