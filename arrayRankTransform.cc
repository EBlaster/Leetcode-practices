#include <headers.h>

class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sorted = arr;
    vector<int> rank(arr.size());
    sort(sorted.begin(), sorted.end());
    sorted.resize(unique(sorted.begin(),sorted.end())-sorted.begin());

    for (int i = 0; i < arr.size(); i++) {
      rank[i] = upper_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() + 1;
    }

    return rank;
  }
};