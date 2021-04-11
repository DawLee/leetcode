// coding Interview 4_3
// 特定深度节点链表
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        if (nullptr == tree) {
            return {nullptr};
        }
        vector<ListNode *> res;
        queue<TreeNode *> record;
        record.emplace(tree);
        ListNode *first = new ListNode(0);
        ListNode *preListNode = nullptr;
        TreeNode *curTreeNode = nullptr;
        int len = 0;
        while (!record.empty()) {
            len = record.size();
            preListNode = first;
            for (int i = 0; i < len; ++i) {
                curTreeNode = record.front();
                record.pop();
                ListNode *tmp = new ListNode(curTreeNode->val);
                preListNode->next = tmp;
                preListNode = tmp;
                if (nullptr != curTreeNode->left) {
                    record.emplace(curTreeNode->left);
                }
                if (nullptr != curTreeNode->right) {
                    record.emplace(curTreeNode->right);
                }
            }
            res.emplace_back(first->next);
            first->next = nullptr;
        }
        delete first;
        first = nullptr;
        return res;
    }
};