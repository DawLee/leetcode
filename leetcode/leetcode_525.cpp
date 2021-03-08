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

// 记录首次count的位置
class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return 0;
        }
        int res = 0;
        int count = 0;
        unordered_map<int, int> record = {{0, -1}};
        for (int i = 0; i < len; ++i) {
            count += (nums[i] == 0) ? -1 : 1;
            if (record.find(count) == record.end()) {
                record.emplace(make_pair(count, i));
            } else {
                res = res > i - record[count] ? res : i - record[count];
            }
        }
        return res;
    }
};

// 超时  X
class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return 0;
        }
        int res = 0;
        int pre = 0;
        int tmp = 0;
        int s = 0;                                  // 个数
        int n = 1;                                  //
        int j = 0;                                  // 坐标
        unordered_map<int, int> record = {{0, -1}}; // <index, num_0
        for (int i = 0; i < len; ++i) {
            tmp = (nums[i] == 0) ? pre + 1 : pre;
            record.emplace(make_pair(i, tmp));
            cout << i << ',' << tmp << endl;
            n = 1;
            s = res + 2 * n;
            j = i - s;
            while (j >= -1) {
                if (nums[i] - nums[j] == s / 2) {
                    res += 2;
                }
                ++n;
                s = res + 2 * n;
                j = i - s;
            }
        }
        return res;
    }
};