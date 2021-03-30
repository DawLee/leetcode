/*
132模式
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void traversal(TreeNode *cur, vector<int> &vec) {
    if (nullptr == cur) {
        return;
    }
    vec.emplace_back(cur->val);
    traversal(cur->left, vec);
    traversal(cur->right, vec);
}

vector<int> preOrderTravesral(TreeNode *root) {
    stack<TreeNode *> record;
    vector<int> res;
    if (nullptr == root)
        return res;
    record.emplace(root);
    while (!record.empty()) {
        TreeNode *cur = record.top();
        record.pop();
        res.emplace_back(cur->val); // 中
        if (nullptr != cur->right)
            record.emplace(cur->right); // 右
        if (nullptr != cur->left)
            record.emplace(cur->left); // 左
    }
    return res;
}

vector<int> postOrderTravesral(TreeNode *root) {
    stack<TreeNode *> record;
    vector<int> res;
    if (nullptr == root)
        return res;
    record.emplace(root);
    while (!record.empty()) {
        TreeNode *cur = record.top();
        record.pop();
        res.emplace_back(cur->val); // 中
        if (nullptr != cur->left)
            record.emplace(cur->left); // 左
        if (nullptr != cur->right)
            record.emplace(cur->right); // 右
    }
    reverse(res.begin(), res.end()); // 反转即为后序遍历
    return res;
}

vector<int> inOrderTravesral(TreeNode *root) {
    stack<TreeNode *> record;
    vector<int> res;
    TreeNode *cur = root;
    while (nullptr != cur || !record.empty()) {
        if (nullptr != cur) {    // 指针访问左节点，访问到最低层
            record.emplace(cur); // 将访问的节点压到栈中
            cur = cur->left;     // 左
        } else {
            cur = record.top(); // 从栈里弹出时才对数据进行处理
            record.pop();
            res.emplace_back(cur->val); // 中
            cur = cur->right;           // 右
        }
    }
    return res;
}

vector<vector<int>> levelOrderTravesral(TreeNode *root) {
    vector<vector<int>> res;
    if (nullptr == root)
        return res;
    queue<TreeNode *> record;
    record.emplace(root);
    while (!record.empty()) {
        int len = record.size();
        vector<int> vec;
        for (int i = 0; i < len; ++i) {
            TreeNode *cur = record.front();
            record.pop();
            vec.emplace_back(cur->val);
            if (nullptr != cur->left)
                record.emplace(cur->left);
            if (nullptr != cur->right)
                record.emplace(cur->right);
        }
        res.emplace_back(vec);
    }
    return res;
}