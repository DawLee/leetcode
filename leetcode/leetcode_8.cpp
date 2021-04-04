/*
字符串转换整数
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

class Automaton {
    string state;
    int sign;
    long long res;
    const int isSpace = 0;
    const int isSigned = 1;
    const int isNum = 2;
    const int isOther = 3;
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};
    int getCol(char c) {
        if (isspace(c)) {
            return isSpace;
        } else if (c == '+' || c == '-') {
            return isSigned;
        } else if (c >= '0' && c <= '9') {
            return isNum;
        } else {
            return isOther;
        }
    }

  public:
    Automaton() {
        state = "start";
        sign = 1;
        res = 0;
    }
    void read(char c) {
        state = table[state][getCol(c)];
        if (state == "in_number") {
            res = res * 10 + c - '0';
            res = sign == 1 ? min(res, (long long)INT_MAX)
                            : min(res, -(long long)INT_MIN);
        } else if (state == "signed") {
            sign = c == '+' ? 1 : -1;
        }
    }
    int getRes() { return res * sign; }
};

class Solution {
  public:
    int strToInt(string str) {
        Automaton automaton;
        for (const char &c : str) {
            automaton.read(c);
        }
        return automaton.getRes();
    }
};