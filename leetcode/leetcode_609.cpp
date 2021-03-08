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

class Solution {
  public:
    unordered_map<string, vector<string>> record;
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        vector<vector<string>> res;
        string content = "";
        for (auto str : paths) {
            recordFiles(str);
        }
        for (auto key : record) {
            content = key.first;
            if (key.second.size() == 1) {
                continue;
            }
            res.emplace_back(key.second);
        }
        return res;
    }
    void recordFiles(string str) {
        string path = "";
        string name = "";
        string content = "";
        string tmp = "";
        int len = str.size();
        int left = 0;
        int right = str.find(' ');
        path = str.substr(left, right - left);
        left = right + 1;
        while (left < len) {
            right = str.find('(', left);
            name = str.substr(left, right - left);
            left = right + 1;
            right = str.find(')', left);
            content = str.substr(left, right - left);
            recordFile(path, name, content);
            left = right + 2;
        }
    }
    void recordFile(string path, string name, string content) {
        path += '/' + name;
        if (record.find(content) == record.end()) {
            vector<string> tmp;
            record.emplace(make_pair(content, tmp));
        }
        record[content].emplace_back(path);
    }
};