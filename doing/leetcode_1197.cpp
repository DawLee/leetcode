/*
进击的骑士
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

// BFS
class Solution {
  public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) {
            return 0;
        }
        x = abs(x);
        y = abs(y);
        vector<vector<int>> dire = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                                    {2, 1},   {1, 2},   {-1, 2}, {-2, 1}};
        unordered_map<int, unordered_set<int>> visit;
        visit[0].emplace(0);
        queue<vector<int>> record;
        vector<int> start = {0, 0};
        record.emplace(start);
        int step = 0;
        while (!record.empty()) {
            ++step;
            int len = record.size();
            for (int k = 0; k < len; ++k) {
                vector<int> cur = record.front();
                record.pop();
                int curDist = getDist(x, y, cur[0], cur[1]);
                for (vector<int> d : dire) {
                    int i = cur[0] + d[0];
                    int j = cur[1] + d[1];
                    int nextDist = getDist(x, y, i, j);
                    if (visit[i].find(j) != visit[i].end()) {
                        continue;
                    }
                    if (curDist > 4 && nextDist > curDist) {
                        continue;
                    }
                    cout << i << ',' << j << ',' << step << endl;
                    if (i == x && j == y) {
                        return step;
                    }
                    vector<int> next = {i, j};
                    record.emplace(next);
                    visit[i].emplace(j);
                }
            }
        }
        return 0;
    }
    int getDist(int x, int y, int i, int j) { return abs(i - x) + abs(j - y); }
};