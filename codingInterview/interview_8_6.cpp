// coding Interview 8_6
// 汉诺塔
// easy

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    void hanota(vector<int> &A, vector<int> &B, vector<int> &C) {
        int n = A.size();
        move(n, A, B, C);
    }
    void move(int n, vector<int> &A, vector<int> &B, vector<int> &C) {
        if (n == 1) {
            C.emplace_back(A.back());
            A.pop_back();
        } else {
            move(n - 1, A, C, B);
            C.emplace_back(A.back());
            A.pop_back();
            move(n - 1, B, A, C);
        }
    }
};