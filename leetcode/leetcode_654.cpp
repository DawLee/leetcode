/*
最大二叉树
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        int len = nums.size();
        TreeNode *root = new TreeNode();
        helper(nums, root, make_pair(0, len - 1));
        return root;
    }
    void helper(vector<int> &nums, TreeNode *root, pair<int, int> vec) {
        int maxNumIndex = getVecMax(nums, vec);
        cout << maxNumIndex << ',' << nums[maxNumIndex] << endl;
        root->val = nums[maxNumIndex];
        pair<int, int> leftVec(vec.first, maxNumIndex - 1);
        pair<int, int> rightVec(maxNumIndex + 1, vec.second);
        if (leftVec.first <= leftVec.second) {
            TreeNode *leftNode = new TreeNode();
            root->left = leftNode;
            helper(nums, leftNode, leftVec);
        }
        if (rightVec.first <= rightVec.second) {
            TreeNode *rightNode = new TreeNode();
            root->right = rightNode;
            helper(nums, rightNode, rightVec);
        }
    }
    int getVecMax(vector<int> &nums, pair<int, int> vec) {
        int res = vec.first;
        for (int i = vec.first; i <= vec.second; ++i) {
            res = nums[res] > nums[i] ? res : i;
        }
        return res;
    }
};