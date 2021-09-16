#include "headers.h"

class Solution {
 public:
  unordered_map<char, int> charMap;
  int count = 0;

  void recursiveCount(int &count) {
    for (auto &&c : charMap) {
      if (c.second > 0) {
        c.second--;
        count++;
        recursiveCount(count);
        c.second++;
      }
    }
  }

  int numTilePossibilities(string tiles) {
    for (auto &&c : tiles) {
      charMap[c]++;
    }

    recursiveCount(count);

    return count;
  }
};