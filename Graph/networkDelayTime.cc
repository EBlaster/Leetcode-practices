#include "headers.h"

class Solution {
 public:
  int minDistance(vector<int> &dist, vector<bool> &sptSet) {
    int minValue = INT_MAX, minIndex;
    for (int v = 0; v < dist.size(); v++)
      if (sptSet[v] == false && dist[v] <= minValue) {
        minValue = dist[v];
        minIndex = v;
      }
    return minIndex;
  }

  vector<int> dijkstra(vector<vector<int>> &graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> sptSet(n, false);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
      int minVert = minDistance(dist, sptSet);
      sptSet[minVert] = true;
      for (int adjVert = 0; adjVert < n; adjVert++)
        if (!sptSet[adjVert] && graph[minVert][adjVert] != -1 &&
            dist[minVert] != INT_MAX &&
            dist[minVert] + graph[minVert][adjVert] < dist[adjVert])
          dist[adjVert] = dist[minVert] + graph[minVert][adjVert];
    }

    return dist;
  }

  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<int>> graph(n, vector<int>(n, -1));
    for (auto &&i : times) {
      graph[i[0] - 1][i[1] - 1] = i[2];
    }
    vector<int> result = dijkstra(graph, k - 1);
    if (find(result.begin(), result.end(), INT_MAX) != result.end()) {
      return -1;
    } else {
      return *max_element(result.begin(), result.end());
    }
  }
};