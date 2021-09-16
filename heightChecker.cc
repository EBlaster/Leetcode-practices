#include "headers.h"

class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> expected = heights;
    int result = 0;
    sort(expected.begin(), expected.end());
    for (int i = 0; i < heights.size(); i++) {
      if (expected[i] != heights[i]) {
        result++;
      }
    }
    return result;
  }
};