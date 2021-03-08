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

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
  public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int mid = 0;
        int tmp = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            // cout << left << ',' << mid << ',' << right << endl;
            tmp = guess(mid);
            if (tmp == 0) {
                return mid;
            } else if (tmp == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return 0;
    }
};