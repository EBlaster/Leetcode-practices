#include "headers.h"

class Solution {
 public:
  bool checkRecord(string s) {
    vector<int> record;
    for (auto &&c : s) {
      switch (c) {
        case 'P':
          record.push_back(0);
          break;
        case 'L':
          record.push_back(1);
          break;
        case 'A':
          record.push_back(2);
          break;
        default:
          break;
      }
    }

    if (count(record.begin(), record.end(), 2) >= 2) {
      return false;
    }

    if (record.size() < 3) {
      return true;
    }

    for (int i = 0; i < record.size() - 2; i++) {
      if (record[i] == 1 && record[i + 1] == 1 && record[i + 2] == 1) {
        return false;
      }
    }

    return true;
  }
};