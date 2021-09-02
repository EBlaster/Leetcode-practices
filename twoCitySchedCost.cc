#include <headers.h>

class Solution {
public:
  static bool compareCosts (vector<int>& c1, vector<int>&c2) {
    return c1[0] - c1[1] > c2[0] - c2[1];
  }

  int twoCitySchedCost(vector<vector<int>>& costs) {
    int totalCost = 0;
    int n = costs.size();
    sort(costs.begin(), costs.end(), &compareCosts);
    for (int i = 0; i < n; i++) {
      if (i < n / 2) {
        totalCost += costs[i][1];
      } else {
        totalCost += costs[i][0];
      }
    }
    return totalCost;
  }
};