// coding Interview 4_2
// 最小高度树
// easy

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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        int len = nums.size();
        return buildTree(nums, 0, len);
    }
    // 左闭右开
    TreeNode *buildTree(const vector<int> &nums, int first, int last) {
        if (first >= last) {
            return nullptr;
        }
        int mid = first + (last - first) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, first, mid);
        root->right = buildTree(nums, mid + 1, last);
        return root;
    }
};