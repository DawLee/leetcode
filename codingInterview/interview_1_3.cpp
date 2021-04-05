
/*
URL化
easy   *
medium
hard
*/

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    string replaceSpaces(string S, int length) {
        int count = 0;
        for (int i = length - 1; i >= 0; --i) {
            count += S[i] == ' ' ? 1 : 0;
        }
        int len = length + count * 2;
        int left = length - 1;
        int right = len - 1;
        while (right > left) {
            if (S[left] != ' ') {
                S[right--] = S[left--];
                continue;
            }
            S[right--] = '0';
            S[right--] = '2';
            S[right--] = '%';
            --left;
        }
        return S.substr(0, len);
    }
};