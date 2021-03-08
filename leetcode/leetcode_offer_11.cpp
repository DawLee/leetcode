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
    int minArray(vector<int> &numbers) {
        if (numbers.empty()) {
            return 0;
        }
        int len = numbers.size();
        int left = 0;
        int right = len - 1;
        int mid = left;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right]) {
                right = mid;
            } else if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else {
                --right;
            }
            cout << left << ',' << mid << ',' << right << endl;
        }
        return numbers[left];
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