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
    string reverseVowels(string s) {
        if (s.empty()) {
            return s;
        }
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};
        int len = s.size();
        int left = 0;
        int right = len - 1;
        while (left < right) {
            while (left <= len && vowels.find(s[left]) == vowels.end()) {
                ++left;
            }
            while (right >= 0 && vowels.find(s[right]) == vowels.end()) {
                --right;
            }
            if (left < right) {
                swap(s[left], s[right]);
            }
        }
        return s;
    }
};