/*
设计哈希映射
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

class MyHashMap {
  public:
    static const int base = 769;
    vector<list<pair<int, int>>> record;
    static int myHash(int key) { return key % base; }
    /** Initialize your data structure here. */
    MyHashMap() { record.resize(base); }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int n = myHash(key);
        for (auto it = record[n].begin(); it != record[n].end(); ++it) {
            if ((*it).first == key) {
                (*it).second = value;
                return;
            }
        }
        record[n].emplace_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this
     * map contains no mapping for the key */
    int get(int key) {
        int n = myHash(key);
        for (auto it = record[n].begin(); it != record[n].end(); ++it) {
            if ((*it).first == key) {
                return (*it).second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a
     * mapping for the key */
    void remove(int key) {
        int n = myHash(key);
        for (auto it = record[n].begin(); it != record[n].end(); ++it) {
            if ((*it).first == key) {
                record[n].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */