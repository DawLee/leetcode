
/*
二叉的深度
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

// BFS
class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        int res = 0;
        queue<TreeNode *> record;
        record.emplace(root);
        TreeNode *cur = nullptr;
        int len = 0;
        while (!record.empty()) {
            len = record.size();
            for (int i = 0; i < len; ++i) {
                cur = record.front();
                record.pop();
                if (nullptr != cur->left) {
                    record.emplace(cur->left);
                }
                if (nullptr != cur->right) {
                    record.emplace(cur->right);
                }
            }
            ++res;
        }
        return res;
    }
};

// DFS
class Solution {
  public:
    int res;
    int maxDepth(TreeNode *root) {
        res = 0;
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode *root, int cur) {
        if (nullptr == root) {
            res = max(res, cur);
            return;
        }
        ++cur;
        dfs(root->left, cur);
        dfs(root->right, cur);
    }
};