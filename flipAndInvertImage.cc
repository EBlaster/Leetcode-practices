#include "headers.h"

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    vector<vector<int>> reversed;
    for (auto row : image) {
      reverse(row.begin(), row.end());
      reversed.push_back(row);
    }

    for (auto &&row : reversed) {
      for (auto &&pixel : row) {
        pixel = !pixel;
      }
    }

    return reversed;
  }
};