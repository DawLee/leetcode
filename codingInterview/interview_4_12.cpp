// coding Interview 4_12
// 求和路径
// medium

#include "leetcode.h"
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
    unordered_map<int, int> record;
    int res;
    int pathSum(TreeNode *root, int sum) {
        res = 0;
        ++record[0];
        getSumTree(root, 0);
        dfs(root, sum);
        return res;
    }
    void getSumTree(TreeNode *root, int sum) {
        if (nullptr == root) {
            return;
        }
        root->val += sum;
        getSumTree(root->left, root->val);
        getSumTree(root->right, root->val);
    }
    void dfs(TreeNode *root, const int target) {
        if (nullptr == root) {
            return;
        }
        if (record.find(root->val - target) != record.end()) {
            res += record[root->val - target];
        }
        ++record[root->val];
        dfs(root->left, target);
        dfs(root->right, target);
        --record[root->val];
    }
};