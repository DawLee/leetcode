/*
根据身高重建队列
easy
medium *
hard
*/

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
    static bool cmp(vector<int> a, vector<int> b) {
        return (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]));
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        int len = people.size();
        vector<vector<int>> res(len, vector<int>(2, -1));
        sort(people.begin(), people.end(), cmp);
        int tmp = 0;
        for (vector<int> p : people) {
            cout << p[0] << ',' << p[1] << endl;
            int index = 0;
            tmp = p[1];
            for (; index < len; ++index) {
                if (tmp == 0 && res[index][0] == -1) {
                    res[index] = p;
                    break;
                }
                if (tmp > 0) {
                    if (res[index][0] == -1 || res[index][0] == p[0]) {
                        --tmp;
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
  public:
    static bool cmp(vector<int> a, vector<int> b) {
        return (a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]));
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        int len = people.size();
        vector<vector<int>> res(len, vector<int>(2, -1));
        sort(people.begin(), people.end(), cmp);
        int index = 0;
        int target = 0;
        for (int i = 0; i < len; ++i) {
            index = i;
            target = people[i][1];
            while (index > target) {
                swap(people[index], people[index - 1]);
                --index;
            }
        }
        return people;
    }
};