/*
从中序与后序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) {
            return nullptr;
        }
        int len = inorder.size();
        pair<int, int> start(0, len - 1);
        TreeNode *root = new TreeNode(postorder[len - 1]);
        buildTreeHelper(inorder, postorder, start, start, root);
        return root;
    }
    void buildTreeHelper(vector<int> &inorder, vector<int> &postorder,
                         pair<int, int> inOrder, pair<int, int> postOrder,
                         TreeNode *root) {
        if (inOrder.first >= inOrder.second) {
            return;
        }
        pair<int, int> inOrderLeft(
            inOrder.first, getInOrderRight(inorder, inOrder.first,
                                           postorder[postOrder.second]) -
                               1);
        pair<int, int> inOrderRight(inOrderLeft.second + 2, inOrder.second);
        int lenLeft = inOrderLeft.second - inOrderLeft.first + 1;
        int lenRight = inOrderRight.second - inOrderRight.first + 1;
        pair<int, int> postOrderLeft(postOrder.first,
                                     postOrder.first + lenLeft - 1);
        pair<int, int> postOrderRight(postOrderLeft.second + 1,
                                      postOrder.second - 1);
        if (lenLeft > 0) {
            TreeNode *leftNode = new TreeNode(postorder[postOrderLeft.second]);
            root->left = leftNode;
            buildTreeHelper(inorder, postorder, inOrderLeft, postOrderLeft,
                            leftNode);
        }
        if (lenRight > 0) {
            TreeNode *rightNode =
                new TreeNode(postorder[postOrderRight.second]);
            root->right = rightNode;
            buildTreeHelper(inorder, postorder, inOrderRight, postOrderRight,
                            rightNode);
        }
    }
    int getInOrderRight(vector<int> &inorder, int start, int target) {
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
