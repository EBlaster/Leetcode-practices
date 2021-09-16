#include "headers.h"

class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    vector<pair<char, int>> namearr;
    vector<pair<char, int>> typedarr;

    namearr.push_back(make_pair(name[0], 1));
    for (auto &&c : name) {
      if (namearr.back().first == c) {
        namearr.back().second++;
      } else {
        namearr.push_back(make_pair(c, 1));
      }
    }

    typedarr.push_back(make_pair(typed[0], 1));
    for (auto &&c : typed) {
      if (typedarr.back().first == c) {
        typedarr.back().second++;
      } else {
        typedarr.push_back(make_pair(c, 1));
      }
    }

    if (namearr.size() != typedarr.size()) {
      return false;
    } else {
      for (int i = 0; i < namearr.size(); i++) {
        if (namearr[i].first != typedarr[i].first ||
            namearr[i].second > typedarr[i].second) {
          return false;
        }
      }
    }
    return true;
  }
};