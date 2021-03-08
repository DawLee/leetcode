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
    int magicalString(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 3) {
            return 1;
        }
        string num(n + 1, '0');
        int res = 1;
        num[0] = '1';
        num[1] = '2';
        num[2] = '2';
        int right = 3;
        int left = 2;
        char tmp = '2';
        int tmpNum = 0;
        while (right < n) {
            tmpNum = num[left] - '0';
            tmp = '3' - tmp + '0';
            for (int i = 0; i < tmpNum; ++i) {
                num[right + i] = tmp;
            }
            if (tmp == '1') {
                res += tmpNum;
            }
            ++left;
            right += tmpNum;
        }
        while (right >= n) {
            if (num[right] == '1') {
                --res;
            }
            --right;
        }
        return res;
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