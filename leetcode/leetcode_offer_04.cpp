#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                --j;
            } else if (matrix[i][j] < target) {
                ++i;
            }
        }
        return false;
    }
};

int main() {
    Solution test_class;
    string s = "()(()";
    int res = test_class.findNumberIn2DArray(s);
    cout << res << endl;

    getchar();
    return 0;
}