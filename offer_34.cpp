
/*
包含min函数的栈
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
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        backtracking(root, target);
        return res;
    }
    void backtracking(TreeNode *root, int target) {
        if (nullptr == root) {
            return;
        }
        target -= root->val;
        path.emplace_back(root->val);
        if (nullptr == root->left && nullptr == root->right) {
            if (target == 0) {
                res.emplace_back(path);
            }
            path.pop_back();
            return;
        }
        backtracking(root->left, target);
        backtracking(root->right, target);
        path.pop_back();
    }
};