#include "headers.h"

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<int> distanceSquared;
    multimap<int, int> mp;
    vector<vector<int>> result;
    for (auto &&i : points) {
      distanceSquared.push_back(i[0] * i[0] + i[1] * i[1]);
    }

    for (int i = 0; i < points.size(); i++) {
      mp.insert(make_pair(distanceSquared[i], i));
    }

    for (auto const &i : mp) {
      if (result.size() < k) {
        result.push_back(points[i.second]);
      } else {
        break;
      }
    }

    return result;
  }
};