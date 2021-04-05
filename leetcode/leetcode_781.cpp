/*
森林中的兔子
easy
medium *
hard
*/

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> record;
        int res = 0;
        int tmp = 0;
        for (int &n : answers) {
            tmp = n + 1;
            ++record[tmp];
            if (record[tmp] >= tmp) {
                res += tmp;
                record.erase(tmp);
            }
        }
        for (auto &r : record) {
            res += r.first;
        }
        return res;
    }
};