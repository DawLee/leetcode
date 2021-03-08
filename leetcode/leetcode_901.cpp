#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class StockSpanner {
  public:
    stack<int> record;
    vector<int> prices;
    int index = 1;
    StockSpanner() {
        record.push(0);
        prices.push_back(INT_MAX);
    }

    int next(int price) {
        int res = 0;
        prices.push_back(price);
        while (!record.empty() && prices[record.top()] <= price) {
            record.pop();
        }
        res = index - record.top();
        record.push(index);
        ++index;
        return res;
    }
};

int main() {
    Solution test_class;
    string test = "3+2*4";
    int res = test_class.calculate(test);
    cout << res << endl;

    getchar();
    return 0;
}