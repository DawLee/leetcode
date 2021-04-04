
/*
二叉搜索树的第k大节点
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
    int kthLargest(TreeNode *root, int k) {
        if (nullptr == root) {
            return 0;
        }
        int res = kthLargest(root->right, k);
        if (--k == 0) {
            return root->val;
        }
        return k < 0 ? res : kthLargest(root->left, k);
    }
};
