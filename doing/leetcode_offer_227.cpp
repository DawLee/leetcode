#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int calculate(string s) {
        if (s.empty()) {
            return 0;
        }
        int res = 0;
        int len = s.size();
        vector<string> record = readString(s);
        for (int i = 0; i < record.size(); ++i) {
            cout << record[i] << ',';
        }
        cout << endl;

        // stack<int> calcu;
        return res;
    }
    vector<string> readString(string s) {
        unordered_map<string, int> symbol = {
            {"+", 0}, {"-", 0}, {"*", 1}, {"/", 1}};
        vector<string> res;
        s += ' ';
        int len = s.size();
        string str = "";
        string sym = "";
        for (int i = 0; i < len; ++i) {
            if (isdigit(s[i])) {
                str += s[i];
                continue;
            }
            if (str == " ") {
                continue;
            }
            res.push_back(str);
            str = "";
            str += s[i];
            if (str == " ") {
                continue;
            }
            if (symbol[sym] == '0') {
                sym = str;
                continue;
            }
            if (symbol[sym] >= symbol[str]) {
                res.push_back(sym);
                sym = str;
            } else {
                res.push_back(str);
            }
        }
        return res;
    }
};

int main() {
    Solution test_class;
    string test = "3+2*4";
    int res = test_class.calculate(test);
    cout << res << endl;

    getchar();
    return 0;
}