#include "headers.h"

class Solution {
 public:
  void dfs(int curr, vector<int> &color,
           unordered_map<int, unordered_set<int>> &graph,
           vector<bool> &visited) {
    visited[curr] = true;
    vector<bool> colorUsed(4, false);
    for (auto adj : graph[curr]) {
      colorUsed[color[adj] - 1] = true;
      if (count(colorUsed.begin(), colorUsed.end(), true) == 3) {
        break;
      }
      if (count(colorUsed.begin(), colorUsed.end(), true) == 4) {
        cout << "ERROR" << endl;
        break;
      }
    }
    for (int i = 0; i < 4; i++) {
      if (!colorUsed[i]) {
        color[curr] = i + 1;
        break;
      }
    }
    for (auto adj : graph[curr]) {
      if (!visited[adj]) {
        dfs(adj, color, graph, visited);
      }
    }
  }

  vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
    unordered_map<int, unordered_set<int>> graph;
    vector<int> color(n + 1, 1);
    vector<bool> visited(n + 1, false);
    for (auto &&path : paths) {
      graph[path[0]].insert(path[1]);
      graph[path[1]].insert(path[0]);
    }

    while (true) {
      int next = find(visited.begin() + 1, visited.end(), false) - visited.begin();
      if (next != visited.end() - visited.begin()) {
        dfs(next, color, graph, visited);
      } else {
        break;
      }
    }

    color.erase(color.begin());
    return color;
  }
};