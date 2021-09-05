#include "headers.h"

class Solution {
public:
  int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    int t = 0;
    int n = calories.size();
    int points = 0;

    for (int i = 0; i < k; i++) {
      t += calories[i];
    }

    for (int i = 0; i < n-k; i++) {
      if (t < lower) {
        points--;
      } else if (t > upper) {
        points++;
      }

      t -= calories[i];
      t += calories[i + k];
    }

    if (t < lower) {
      points--;
    } else if (t > upper) {
      points++;
    }

    return points;
  }
};