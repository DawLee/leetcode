#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
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
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if (numerator < 0 && denominator > 0 ||
            numerator > 0 && denominator < 0) {
            res += '-';
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        long z = numerator / denominator;
        long y = numerator % denominator;
        res += to_string(z);
        if (y == 0) {
            return res;
        }
        res += '.';
        unordered_map<int, int> record;
        string dec = "";
        int tmp = 0;
        int begin = -1;
        int index = 0;
        while (y != 0) {
            y %= denominator;
            if (y == 0) {
                break;
            }
            if (record.find(y) != record.end()) {
                begin = record[y];
                break;
            } else {
                record.insert(make_pair(y, index));
            }
            y *= 10;
            tmp = y / denominator;
            dec += to_string(tmp);
            ++index;
        }
        if (begin == -1) {
            res += dec;
            return res;
        }
        res += dec.substr(0, begin);
        res += '(';
        res += dec.substr(begin, index - begin);
        res += ')';
        return res;
    }
};