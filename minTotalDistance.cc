#include "headers.h"

class Solution {
 public:
  int minTotalDistance(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> friendPos;
    vector<vector<int>> distMap(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          friendPos.push_back({i, j});
        }
      }
    }

    int minDist = INT_MAX;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int currDist = 0;
        for (auto &&f : friendPos) {
          currDist += abs(f[0] - i) + abs(f[1] - j);
        }
        if (currDist < minDist) {
          minDist = currDist;
        }
      }
    }

    return minDist;
  }
};