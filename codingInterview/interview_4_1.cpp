// coding Interview 4_1
// 节点间通路
// medium

#include "leetcode.h"
using namespace std;

class Solution {
  public:
    unordered_map<int, vector<int>> myGraph;
    unordered_set<int> visit;
    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start,
                               int target) {
        buildGraph(graph);
        return dfs(target, start);
    }
    void buildGraph(const vector<vector<int>> &vec) {
        const vector<int> tmp;
        for (const auto &path : vec) {
            if (myGraph.find(path[0]) == myGraph.end()) {
                myGraph.emplace(make_pair(path[0], tmp));
            }
            myGraph[path[0]].emplace_back(path[1]);
        }
    }
    bool dfs(const int target, const int node) {
        if (node == target) {
            return true;
        }
        if (myGraph.find(node) == myGraph.end() ||
            visit.find(node) != visit.end()) {
            return false;
        }
        visit.emplace(node);
        for (const int n : myGraph[node]) {
            if (dfs(target, n)) {
                return true;
            }
        }
        return false;
    }
};