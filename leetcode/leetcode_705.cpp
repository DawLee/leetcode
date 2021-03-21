/*
设计哈希集合
easy   *
medium
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

class MyHashSet {
  public:
    vector<list<int>> record;
    static const int base = 769;
    static int myHash(int num) { return num % base; }
    /** Initialize your data structure here. */
    MyHashSet() { record.resize(769); }

    void add(int key) {
        int n = myHash(key);
        for (auto it = record[n].begin(); it != record[n].end(); ++it) {
            if ((*it) == key) {
                return;
            }
        }
        record[n].emplace_back(key);
    }

    void remove(int key) {
        int n = myHash(key);
        for (auto it = record[n].begin(); it != record[n].end(); ++it) {
            if ((*it) == key) {
                record[n].erase(it);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int n = myHash(key);
        for (auto it = record[n].begin(); it != record[n].end(); ++it) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */