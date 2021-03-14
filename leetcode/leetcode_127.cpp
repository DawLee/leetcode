/*
单词接龙
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

// double BFS, 超时
class Solution {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        int len = wordList.size();
        int wordLen = beginWord.size();
        bool isHaveBeginWord = false;
        bool isHaveEndWord = false;
        int beginIndex = -1;
        int endIndex = -1;
        // wordList里面是否有beginWord和endWord
        for (int i = 0; i < len; ++i) {
            if (wordList[i] == beginWord) {
                isHaveBeginWord = true;
                beginIndex = i;
            }
            if (wordList[i] == endWord) {
                isHaveEndWord = true;
                endIndex = i;
            }
            if (isHaveBeginWord && isHaveEndWord) {
                break;
            }
        }
        if (!isHaveEndWord) {
            return 0;
        }
        if (beginIndex == -1) {
            wordList.emplace_back(beginWord);
            beginIndex = len;
            ++len;
        }
        if (beginWord == endWord) {
            return 0;
        }
        // 查找任意两个只差一个字母的单词，构建graph
        vector<vector<int>> graph(len);
        for (int i = 0; i < len - 1; ++i) {
            for (int j = 0; j < len; ++j) {
                if (i != j && isConnect(wordList[i], wordList[j], wordLen)) {
                    graph[i].emplace_back(j);
                    graph[j].emplace_back(i);
                }
            }
        }
        // double BFS
        vector<int> distanceBegin(len, INT_MAX);
        queue<int> recordBegin;
        recordBegin.emplace(beginIndex);
        distanceBegin[beginIndex] = 1;

        vector<int> distanceEnd(len, INT_MAX);
        queue<int> recordEnd;
        recordEnd.emplace(endIndex);
        distanceEnd[endIndex] = 1;

        int step = 1;
        while (!recordBegin.empty() && !recordEnd.empty()) {
            ++step;
            // begin BFS
            int recordBeginLen = recordBegin.size();
            for (int k = 0; k < recordBeginLen; ++k) {
                int cur = recordBegin.front();
                recordBegin.pop();
                for (int i : graph[cur]) {
                    if (distanceEnd[i] != INT_MAX) {
                        return step + distanceEnd[i] - 1;
                    }
                    if (distanceBegin[i] == INT_MAX) {
                        recordBegin.emplace(i);
                        distanceBegin[i] = step;
                    }
                }
            }
            // end BFS
            int recordEndLen = recordEnd.size();
            for (int k = 0; k < recordEndLen; ++k) {
                int cur = recordEnd.front();
                recordEnd.pop();
                for (int i : graph[cur]) {
                    if (distanceBegin[i] != INT_MAX) {
                        return step + distanceBegin[i] - 1;
                    }
                    if (distanceEnd[i] == INT_MAX) {
                        recordEnd.emplace(i);
                        distanceEnd[i] = step;
                    }
                }
            }
        }
        return 0;
    }
    bool isConnect(const string a, const string b, int len) {
        bool flag = false;
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                if (flag) {
                    return false;
                } else {
                    flag = true;
                }
            }
        }
        return true;
    }
};

// bfs剪枝
class Solution {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        if (word_set.count(endWord) == 0) {
            return 0;
        }
        int len = beginWord.size();
        queue<string> record;
        record.emplace(beginWord);
        word_set.erase(beginWord);
        int step = 1;
        while (!record.empty()) {
            ++step;
            int recordLen = record.size();
            for (int k = 0; k < recordLen; ++k) {
                string cur = record.front();
                vector<string> tmp;
                record.pop();
                for (const string &word : word_set) {
                    if (isConnect(cur, word, len)) {
                        if (word == endWord) {
                            return step;
                        }
                        record.emplace(word);
                        tmp.emplace_back(word);
                    }
                }
                for (const string &word : tmp) {
                    word_set.erase(word);
                }
            }
        }
        return 0;
    }
    bool isConnect(const string a, const string b, int len) {
        bool flag = false;
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                if (flag) {
                    return false;
                } else {
                    flag = true;
                }
            }
        }
        return true;
    }
};