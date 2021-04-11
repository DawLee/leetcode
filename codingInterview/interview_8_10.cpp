// coding Interview 8_10
// 颜色填充
// easy

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        if (image.empty() || image[sr][sc] == newColor) {
            return image;
        }
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> dire = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        const int LEN = dire.size();
        const int srcColor = image[sr][sc];
        queue<pair<int, int>> record;
        record.emplace(make_pair(sr, sc));
        pair<int, int> cur = {0, 0};
        pair<int, int> next = {0, 0};
        while (!record.empty()) {
            cur = record.front();
            record.pop();
            image[cur.first][cur.second] = newColor;
            for (int i = 0; i < LEN; ++i) {
                next.first = cur.first + dire[i][0];
                next.second = cur.second + dire[i][1];
                if (isLegal(row, col, next) &&
                    image[next.first][next.second] == srcColor) {
                    record.emplace(next);
                }
            }
        }
        return image;
    }
    bool isLegal(const int row, const int col, pair<int, int> cur) {
        if (cur.first < 0 || cur.first >= row || cur.second < 0 ||
            cur.second >= col) {
            return false;
        }
        return true;
    }
};