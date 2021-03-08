#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string replaceSpace(string s) {
        if (s.empty()) {
            return s;
        }
        int len = s.size();
        int numSpace = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') {
                ++numSpace;
            }
        }
        s.append(numSpace * 2, ' ');
        string space = "%20";
        int lenSpace = space.size();
        int lenRes = s.size();
        int left = len - 1;
        int right = lenRes - 1;
        while (left != right && left >= 0) {
            while (s[left] != ' ') {
                s[right] = s[left];
                --left;
                --right;
            }
            for (int j = lenSpace - 1; j >= 0; --j) {
                s[right] = space[j];
                --right;
            }
            --left;
        }
        return s;
    }
};

int main() {
    // Solution test_class;
    // string s = "abc defg";
    // string res = test_class.replaceSpace(s);
    // cout << res << endl;
    string test = "trst";
    string res(10, '*');
    res.replace(0, test.size(), test);
    cout << res << endl;

    getchar();
    return 0;
}