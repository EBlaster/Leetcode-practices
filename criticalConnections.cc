#include <headers.h>

class Solution {
 public:
  vector<bool> visited;
  vector<int> tin, low;
  vector<vector<int>> bridge;
  int timer;

  void dfs(vector<vector<int>>& adj, int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
      if (to == p) continue;
      if (visited[to]) {
        low[v] = min(low[v], tin[to]);
      } else {
        dfs(adj, to, v);
        low[v] = min(low[v], low[to]);
        if (low[to] > tin[v]) IS_BRIDGE(v, to);
      }
    }
  }

  void find_bridges(vector<vector<int>>& adj, int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) dfs(adj, i);
    }
  }

  void IS_BRIDGE(int v, int to) {
    vector<int> tmp;
    tmp.push_back(v);
    tmp.push_back(to);
    bridge.push_back(tmp);
  }

  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>>& connections) {
    vector<vector<int>> adj(10000);
    for (int i = 0; i < connections.size(); i++) {
      adj[connections[i][0]].push_back(connections[i][1]);
      adj[connections[i][1]].push_back(connections[i][0]);
    }
    find_bridges(adj, n);
    return bridge;
  }
};