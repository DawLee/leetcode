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

class Solution {
  public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return {0};
        }
        int len = intervals.size();
        vector<int> res(len, 0);
        unordered_map<int, int> indexMap;
        vector<vector<int>> record(intervals);
        sort(record.begin(), record.end());
        int tmp = 0;
        for (int i = 0; i < len; ++i) {
            indexMap.emplace(make_pair(intervals[i][0], i));
        }
        for (int i = 0; i < len; ++i) {
            tmp = getRightIndex(record, intervals[i][1]);
            tmp = (tmp == -1) ? -1 : indexMap[record[tmp][0]];
            res[i] = tmp;
        }
        return res;
    }
    int getRightIndex(vector<vector<int>> &record, int n) {
        int len = record.size();
        if (record[len - 1][0] < n) {
            return -1;
        }
        int left = 0;
        int right = len - 1;
        int mid = 0;
        int tmp = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            tmp = record[mid][0];
            if (tmp == n) {
                return mid;
            } else if (tmp < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    vector<vector<int>> test;
    test.push_back({3, 4});
    test.push_back({2, 3});
    test.push_back({1, 2});
    sort(test.begin(), test.end());
    int len = test.size();
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < test[i].size(); ++j) {
            cout << test[i][j] << ',';
        }
        cout << endl;
    }
    getchar();
    return 0;
}