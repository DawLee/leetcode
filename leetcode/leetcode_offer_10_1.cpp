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
    int fib(int n) {
        int mo = pow(10, 9) + 7;
        int a = 0;
        int b = 1;
        int c = b;
        if (n == 0) {
            return a;
        }
        if (n == 1) {
            return 1;
        }
        for (int i = 2; i < n; ++i) {
            a = b;
            b = c;
            c = a + b;
            if (c > mo) {
                c %= mo;
            }
        }
        return c;
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