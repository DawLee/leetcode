/*
序列化二叉树
easy
medium
hard   *
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

class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (nullptr == root) {
            return "";
        }
        vector<string> res;
        queue<TreeNode *> record;
        record.emplace(root);
        bool flag = false; //下一层节点是否全是null
        vector<string> layer;
        TreeNode *tmp = nullptr;
        int len = 0;
        while (true) {
            len = record.size();
            for (int i = 0; i < len; ++i) {
                tmp = record.front();
                record.pop();
                if (nullptr == tmp) {
                    layer.emplace_back("null");
                    continue;
                }
                layer.emplace_back(to_string(tmp->val));
                record.emplace(tmp->left);
                record.emplace(tmp->right);
                if (nullptr != tmp->left || nullptr != tmp->right) {
                    flag = true;
                }
            }
            if (!flag) {
                break;
            }
            for (string &str : layer) {
                res.emplace_back(str);
            }
            flag = false;
            layer.clear();
        }
        string reault = vecToString(res);
        return reault;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {}

    string vecToString(vector<string> &vec) {
        string res = "";
        if (vec.empty()) {
            return res;
        }
        for (string &str : vec) {
            res += ',' + str;
        }
        res[0] = '[';
        res += ']';
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));